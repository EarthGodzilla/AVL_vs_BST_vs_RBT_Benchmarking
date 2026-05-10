#pragma once

enum Color { RED, BLACK };

struct RBTNode {
    int key;
    Color color;
    RBTNode *left, *right, *parent;

    explicit RBTNode(int k);
};

class RBT {
public:
    RBT();
    ~RBT();

    void insert(int key);
    bool search(int key) const;
    int height() const;

private:
    RBTNode *root;

    void rotateLeft(RBTNode *x);
    void rotateRight(RBTNode *y);
    void fixInsert(RBTNode *z);

    bool search(RBTNode *node, int key) const;
    int height(RBTNode *node) const;
    void destroy(RBTNode *node);
};