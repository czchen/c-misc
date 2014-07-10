#include <rbtree.h>

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
