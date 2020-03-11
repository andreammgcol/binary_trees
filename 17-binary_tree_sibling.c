#include "binary_trees.h"

/**
 * binary_tree_sibling - function finds the sibling of a node
 * @node:  is a pointer to the node to be evaluated
 * Return: a pointer to the sibling node
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling_nodel = NULL, *sibling_noder = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	sibling_nodel = node->parent->left;
	sibling_noder = node->parent->right;
	if (sibling_nodel != node)
		return (sibling_nodel);
	else
		return (sibling_noder);
}
