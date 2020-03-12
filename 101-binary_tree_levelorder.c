#include "binary_trees.h"

/**
 * binary_tree_levelorder - through a binary tree using level-order traversal
 * @tree: root of the binary tree
 * @func: pointer to a function
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, height = 0;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (i = 1; i <= height + 1; i++)
	{
		iterate_level(tree, func, i);
	}
	return;

}

/**
 * iterate_level - that iterate the level of a binary tree
 * @tree: root of the binary tree
 * @func: pointer to a function
 * @level: level of binary tree
*/
void iterate_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	if (level > 1)
	{
		iterate_level(tree->left, func, level - 1);
		iterate_level(tree->right, func, level - 1);
	}
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
