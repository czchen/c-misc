#include <rbtree.h>

#include <stdlib.h>

int init_rbtree(struct RBTree *tree)
{
    if (!tree) {
        return -1;
    }

    tree->root = NULL;

    return 0;
}

void destroy_rbtree(struct RBTree *tree)
{
    if (tree) {
        // FIXME: free tree->root
        tree->root = NULL;
    }
}
