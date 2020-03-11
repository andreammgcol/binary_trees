#include "binary_trees.h"

/**
 * binary_tree_balance - that measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: The balance factor. If tree is NULL, return 0
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0, balance = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right = binary_tree_height(tree->right) + 1;

	balance = left - right;

	return (balance);
}

/**
 * binary_tree_height - that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_rigth = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		height_rigth = binary_tree_height(tree->right) + 1;
	if (height_left >= height_rigth)
		return (height_left);
	else
		return (height_rigth);
}
