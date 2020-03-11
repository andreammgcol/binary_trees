#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	int count_full = 0;

	if (tree == NULL)
		return (0);
	count_full = binary_tree_uniq(tree);
	if (count_full == 0)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_uniq - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: If tree is NULL, the function must return 0
*/

size_t binary_tree_uniq(const binary_tree_t *tree)
{
	size_t size = 0, size1 = 0, size2 = 0;

	if (tree == NULL)
		return (0);

	size1 = binary_tree_uniq(tree->left);
	size2 = binary_tree_uniq(tree->right);
	size = size1 + size2;
	if ((tree->left == NULL && tree->right == NULL) ||
		 (tree->left != NULL && tree->right != NULL))
		return (size);
	else
		return (size + 1);
}
