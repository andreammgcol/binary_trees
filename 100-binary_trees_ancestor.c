#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest ancestor of two nodes
 * @first:  is a pointer to the first node to be evaluated
 * @second: is a pointer to the second node to be evaluated
 * Return: a pointer to the uncle node
*/

binary_tree_t *binary_trees_ancestor(const
		binary_tree_t *first, const binary_tree_t *second)
{
	size_t fst_depth, snd_depth;
	binary_tree_t *fc = (binary_tree_t *)first, *sc = (binary_tree_t *)second;

	if (first == NULL || second == NULL)
		return (NULL);
	fst_depth =  binary_tree_depth(first), snd_depth = binary_tree_depth(second);
	if (fst_depth > snd_depth)
	{
		while (fst_depth > snd_depth)
		{
			fc = fc->parent;
			fst_depth = fst_depth - 1;
		}
	}
	else if (fst_depth < snd_depth)
	{
		while (fst_depth < snd_depth)
		{
			sc = sc->parent;
			snd_depth = snd_depth - 1;
		}
	}
	if (fst_depth == snd_depth)
	{
		if (fc == sc)
			return (fc);
		if (first == sc)
			return (sc);
		else if (second == fc)
			return (fc);
		while (fc != sc)
		{
			if (fc == NULL || sc == NULL)
				return (NULL);
			fc = fc->parent;
			sc = sc->parent;
		}
			return (fc);
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
