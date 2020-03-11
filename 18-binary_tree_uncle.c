#include "binary_trees.h"

/**
 * binary_tree_uncle - function finds the uncle a node
 * @node:  is a pointer to the node to be evaluated
 * Return: a pointer to the uncle node
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle_nodel = NULL, *uncle_noder = NULL;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	uncle_nodel = node->parent->parent->left;
	uncle_noder = node->parent->parent->right;
	if (uncle_nodel != node->parent)
		return (uncle_nodel);
	else
		return (uncle_noder);
}
