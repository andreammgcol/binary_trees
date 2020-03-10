#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent:  is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL, *tmp_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (parent->right == NULL)
	{
		parent->right = new_node;
	}
	else
	{
		tmp_node = parent->right;
		tmp_node->parent = new_node;
		parent->right = new_node;
		new_node->right = tmp_node;
	}

	return (new_node);
}
