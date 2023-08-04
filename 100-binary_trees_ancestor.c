#include "binary_trees.h"
#include <stdio.h>


/**
 * binary_trees_ancestor -Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node
 * of the two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	return (_binary_trees_ancestor(first, second));
}

/**
 * _binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node
 * of the two given nodes.
 */
binary_tree_t *_binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first->parent == NULL)
	{
		return ((binary_tree_t *)first);
	}
	if (second->parent == NULL)
	{
		return ((binary_tree_t *)second);
	}
	if (first->parent == second->parent)
	{
		return (first->parent);
	}

	first_depth = _binary_tree_depth(first);
	second_depth = _binary_tree_depth(second);

	if (first_depth > second_depth)
	{
		return (_binary_trees_ancestor(first->parent, second));
	}
	if (first_depth < second_depth)
	{
		return (_binary_trees_ancestor(first, second->parent));
	}

	return (_binary_trees_ancestor(first, second));
}

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
