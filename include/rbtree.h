#pragma once

enum Color {
    BLACK,
    RED,
};

struct RBTreeNode {
    enum Color;
    int value;
    struct RBTreeNode *parent;
    struct RBTreeNode *left_child;
    struct RBTreeNode *right_child;
};

struct RBTree {
    struct RBTreeNode *root;
};
