#include "binary_trees.h"

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int count_perfect = 0, balance = 0, count_left = 0, count_right = 0;

	if (tree == NULL)
		return (0);

	count_perfect = tree_count_perfect(tree);
	balance = binary_tree_balance(tree);
	count_left = binary_tree_size(tree->left);
	count_right = binary_tree_size(tree->right);
	if (count_perfect == 0 && balance == 0 && count_left == count_right)
		return (1);
	else
		return (0);
}

/**
 * tree_count_perfect - counts the nodes with at least 1 child without sibling.
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 0 if all the nodes have two child, or >= 1 otherwise
*/

size_t tree_count_perfect(const binary_tree_t *tree)
{
	size_t size = 0, size1 = 0, size2 = 0;

	if (tree == NULL)
		return (0);

	size1 = tree_count_perfect(tree->left);
	size2 = tree_count_perfect(tree->right);
	size = size1 + size2;
	if ((tree->left != NULL && tree->right == NULL) ||
			(tree->right != NULL && tree->left == NULL))
		return (size + 1);
	else
		return (size);
}

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
