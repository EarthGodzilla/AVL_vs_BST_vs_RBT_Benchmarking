#include "avl.h"
//#include "../include/avl.h"
#include <algorithm>
using namespace std;

AVLNode::AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}

AVL::AVL() : root(nullptr) {}

AVL::~AVL() {
    destroy(root);
}

void AVL::destroy(AVLNode *node) {
    if (!node) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

int AVL::height(AVLNode *node) const {
    return node ? node->height : 0;
}

int AVL::balanceFactor(AVLNode *node) const {
    return height(node->left) - height(node->right);
}

AVLNode *AVL::rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *AVL::rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *AVL::insert(AVLNode *node, int key) {
    if (!node) {
        return new AVLNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key){
        return rotateRight(node);
    }else if (balance < -1 && key > node->right->key){
        return rotateLeft(node);
    } else if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    } else if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVL::insert(int key) {
    root = insert(root, key);
}

bool AVL::search(AVLNode *node, int key) const {
    if (!node) {
        return false;
    }
    if (key == node->key) {
        return true;
    }

    return key < node->key ? search(node->left, key) : search(node->right, key);
}

bool AVL::search(int key) const {
    return search(root, key);
}

int AVL::height() const {
    return height(root);
}