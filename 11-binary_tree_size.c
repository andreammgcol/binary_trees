#include "binary_trees.h"

/**
 * binary_tree_size - that measures the size  of Binary tree
 * @tree: pointer to root node of the tree to measure the size
 * Return: If tree is NULL, your function must return 0
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, size1 = 0, size2 = 0;

	if (tree == NULL)
		return (0);

	size1 = binary_tree_size(tree->left);
	size2 = binary_tree_size(tree->right);
	size = size1 + size2;
	return (size + 1);
}
