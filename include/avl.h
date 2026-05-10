#pragma once
//naming folder include tells compiler to lookj inside automaticaly
struct AVLNode {
    int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    explicit AVLNode(int k);
};

class AVL {
public:
    AVL();
    ~AVL();

    void insert(int key);
    bool search(int key) const;
    int height() const;

private:
    AVLNode *root;

    AVLNode *insert(AVLNode *node, int key);
    bool search(AVLNode *node, int key) const;

    int height(AVLNode *node) const;
    int balanceFactor(AVLNode *node) const;

    AVLNode *rotateRight(AVLNode *y);
    AVLNode *rotateLeft(AVLNode *x);

    void destroy(AVLNode *node);
};