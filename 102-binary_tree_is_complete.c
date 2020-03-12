#include "binary_trees.h"

/**
 * binary_tree_is_complete - that checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count_left = 0, count_right = 0;
	int l_height = 0, r_height = 0;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);
	count_left = binary_tree_size(tree->left);
	count_right = binary_tree_size(tree->right);
	if ((count_left >= count_right) || (l_height >= r_height))
		return (1);
	else
		return (0);

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
