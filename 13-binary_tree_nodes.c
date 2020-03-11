#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: If tree is NULL, the function must return 0
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size = 0, size1 = 0, size2 = 0;

	if (tree == NULL)
		return (0);

	size1 = binary_tree_nodes(tree->left);
	size2 = binary_tree_nodes(tree->right);
	size = size1 + size2;
	if (tree->left == NULL && tree->right == NULL)
		return (size);
	else
		return (size + 1);
}
