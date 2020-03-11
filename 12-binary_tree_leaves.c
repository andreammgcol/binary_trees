#include "binary_trees.h"

/**
 * binary_tree_leaves - that counts the leaves in a Binary tree
 * @tree: pointer to root node of the tree
 * Return: If tree is NULL, your function must return 0
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t n_leaves = 0, size = 0, size1 = 0, size2 = 0;

	if (tree == NULL)
		return (0);

	size1 = binary_tree_leaves(tree->left);
	size2 = binary_tree_leaves(tree->right);
	n_leaves = binary_tree_is_leaf(tree);
	size = size1 + size2;
	if (n_leaves == 1)
		return (size + 1);
	else
		return (size);
}
