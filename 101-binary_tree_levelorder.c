#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal.
 * @tree: root of the binary tree
 * @func: pointer to a function
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		binary_tree_levelorder(tree->left, func);
		binary_tree_levelorder(tree->right, func);
	}
}
