#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest ancestor of two nodes
 * @first:  is a pointer to the first node to be evaluated
 * @second: is a pointer to the second node to be evaluated
 * Return: a pointer to the uncle node
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;
	binary_tree_t *first_copy, *second_copy;



	if (first == NULL || second == NULL)
		return (NULL);
	first_copy = (const binary_tree_t) first;
	second_copy = (const binary_tree_t) second;
	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	if (first_depth > second_depth)
	{
		while (first_depth > second_depth)
		{
			first_copy = first_copy->parent;
			first_depth = first_depth - 1;

		}
	}
	else if (first_depth < second_depth)
	{
		while (first_depth < second_depth)
		{
			second_copy = second_copy->parent;
			second_depth = second_depth -1;
		}
	}
	if (first_depth == second_depth)
	{
		if (first_copy == second_copy)
			return (first_copy);
		if (first == second_copy)
			return (second_copy);
		else if (second == first_copy)
			return (first_copy);
		else
		{
			while (first_copy != second_copy)
			{
				if (first_copy == NULL || second_copy == NULL)
					return (NULL);
				first_copy = first_copy->parent;
				second_copy = second_copy->parent;
			}
			return (first_copy);
		}
	}
	return (NULL);
}

/**
 * binary_tree_depth - that measures the depth of a node in a binary tree
 * @tree: pointer to the node of the tree to measure the depth
 * Return: If tree is NULL, your function must return 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	if (tree->parent == NULL)
		return (0);
	depth = binary_tree_depth(tree->parent) + 1;
	return (depth);
}
