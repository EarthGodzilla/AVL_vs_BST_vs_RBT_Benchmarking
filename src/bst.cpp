//#include "../include/bst.h"
#include "bst.h"
#include <algorithm>
using namespace std;

BSTNode::BSTNode(int k) : key(k), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

BST::~BST() {
    destroy(root);
}

void BST::destroy(BSTNode *node) {
    if (!node) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

BSTNode *BST::insert(BSTNode *node, int key) {
    if (!node) {
        return new BSTNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }

    return node;
}

void BST::insert(int key) {
    root = insert(root, key);
}

bool BST::search(BSTNode *node, int key) const {
    if (!node) {
        return false;
    }
    if (key == node->key) {
        return true;
    }

    return key < node->key ? search(node->left, key) : search(node->right, key);
}

bool BST::search(int key) const {
    return search(root, key);
}

int BST::height(BSTNode *node) const {
    if (!node) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

int BST::height() const {
    return height(root);
}