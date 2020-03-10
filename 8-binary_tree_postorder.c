#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through binary tree using post-order traversal.
 * @tree: root of the binary tree
 * @func: pointer to a function
*/

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
		func(tree->n);
	}
}
