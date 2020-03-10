#include "binary_trees.h"

/**
 * binary_tree_delete - that deletes an entire binary tree
 * @tree: is a pointer to the root node of the tree to delete
 * Return: nothing
*/

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{

		if (tree->left)
		{
			binary_tree_delete(tree->left);
		}
		if (tree->right)
		{
			binary_tree_delete(tree->right);
		}
		free(tree);
	}
}
