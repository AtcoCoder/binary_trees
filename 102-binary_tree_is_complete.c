#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to traverse
 *
 * Return: 1 if binary tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
	{
		return (0);
	}

	size = binary_tree_size(tree);

	return (_binary_tree_is_complete(tree, 0, size));
}


/**
 * _binary_tree_is_complete - Helper function to traverse a binary tree
 * using index-order traversal and check if the tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 * @index: The level of a binary tree to traverse.
 * @size: The number of node in the tree.
 *
 * Return: 1 is tree is complete, otherwise 0.
 */
int _binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (index >= size)
	{
		return (0);
	}

	return ((_binary_tree_is_complete(tree->left, 2 * index + 1, size)) &&
		(_binary_tree_is_complete(tree->right, 2 * index + 2, size)));
}


/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: Size of a binary tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
	}
}
