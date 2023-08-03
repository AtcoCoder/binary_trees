#include "binary_trees.h"


/**
 * _binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to the node to measure the depth
 *
 * Return: The depth of a node in a binary tree.
 */
size_t _binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (-1);
	}
	return (_binary_tree_depth(tree->parent) + 1);
}


/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to the node to measure the depth
 *
 * Return: The depth of a node in a binary tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (_binary_tree_depth(tree));
}
