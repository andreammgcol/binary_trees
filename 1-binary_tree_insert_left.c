#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent:  is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL, *tmp_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else
	{
		tmp_node = parent->left;
		tmp_node->parent = new_node;
		parent->left = new_node;
		new_node->left = tmp_node;
	}

	return (new_node);

}
