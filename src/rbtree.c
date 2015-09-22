#include <rbtree.h>

#include <assert.h>
#include <stdlib.h>

int rb_init(struct RBTree *tree)
{
    if (!tree) {
        return -1;
    }

    tree->root = NULL;

    return 0;
}

void rb_destroy(struct RBTree *tree)
{
    if (tree) {
        // FIXME: free tree->root
        tree->root = NULL;
    }
}

static struct RBTreeNode *new_tree_node(int value)
{
    struct RBTreeNode *node = malloc(sizeof(*node));
    if (!node) {
        return node;
    }

    node->color = RED;
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}

// return insert point of the value, NULL means value already in node.
static struct RBTreeNode **find_insert_point(struct RBTree *tree, int value)
{
    assert(tree);

    struct RBTreeNode **node = &tree->root;

    while (*node) {
        if ((*node)->value < value) {
            node = &(*node)->left_child;
        } else if ((*node)->value < value) {
            node = &(*node)->right_child;
        } else {
            return NULL;
        }
    }

    return node;
}

// 1 means the value is in tree, 0 otherwise.
int rb_search(struct RBTree *tree, int value)
{
    if (!tree) {
        return 0;
    }

    return !find_insert_point(tree, value);
}

int rb_insert(struct RBTree *tree, int value)
{
    if (!tree) {
        return -1;
    }

    struct RBTreeNode **node = find_insert_point(tree, value);

    if (!node) {
        return 0;
    }

    *node = new_tree_node(,value);
    if (!node) {
        return -1;
    }

    // FIXME: rebalance RB tree
}
