#pragma once

enum Color {
    BLACK,
    RED,
};

struct RBTreeNode {
    enum Color color;
    int value;
    struct RBTreeNode *parent;
    struct RBTreeNode *left_child;
    struct RBTreeNode *right_child;
};

struct RBTree {
    struct RBTreeNode *root;
};

int rb_init(struct RBTree *tree);
void rb_destroy(struct RBTree *tree);
