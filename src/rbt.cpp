//#include "../include/rbt.h"
#include "rbt.h"
#include <algorithm>
using namespace std;

RBTNode::RBTNode(int k)  : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}

RBT::RBT() : root(nullptr) {}

RBT::~RBT() {
    destroy(root);
}

void RBT::destroy(RBTNode *node) {
    if (!node) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

void RBT::rotateLeft(RBTNode *x) {
    RBTNode *y = x->right;
    x->right = y->left;

    if (y->left) {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (!x->parent){
        root = y;
    }
    else if (x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RBT::rotateRight(RBTNode *y) {
    RBTNode *x = y->left;
    y->left = x->right;

    if (x->right) {
        x->right->parent = y;
    }
    x->parent = y->parent;

    if (!y->parent){
        root = x;
    }
    else if (y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

void RBT::insert(int key) {
    RBTNode *z = new RBTNode(key), *y = nullptr, *x = root;

    while (x) {
        y = x;
        x = (z->key < x->key) ? x->left : x->right;
    }

    z->parent = y;

    if (!y){
        root = z;
    }
    else if (z->key < y->key){
        y->left = z;
    }
    else{
        y->right = z;
    }

    fixInsert(z);
}

void RBT::fixInsert(RBTNode *z) {
    while (z->parent && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTNode *y = z->parent->parent->right;

            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        } else {
            RBTNode *y = z->parent->parent->left;

            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

bool RBT::search(RBTNode *node, int key) const {
    if (!node) {
        return false;
    }
    if (key == node->key) {
        return true;
    }

    return key < node->key ? search(node->left, key) : search(node->right, key);
}

bool RBT::search(int key) const {
    return search(root, key);
}

int RBT::height(RBTNode *node) const {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int RBT::height() const {
    return height(root);
}