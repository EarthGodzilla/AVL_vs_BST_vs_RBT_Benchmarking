#pragma once
#include <memory>

struct BSTNode {
    int key;
    BSTNode *left;
    BSTNode *right;

    explicit BSTNode(int k);
};

class BST {
public:
    BST();
    ~BST();

    void insert(int key);
    bool search(int key) const;
    int height() const;

private:
    BSTNode *root;

    BSTNode *insert(BSTNode *node, int key);
    bool search(BSTNode *node, int key) const;
    int height(BSTNode *node) const;
    void destroy(BSTNode *node);
};