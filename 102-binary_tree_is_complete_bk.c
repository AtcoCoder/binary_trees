#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to traverse
 *
 * Return: 1 if binary tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t max_level;

	if (tree == NULL)
	{
		return (1);
	}

	max_level = _binary_tree_height(tree) + 1;

	return (_binary_tree_is_complete(tree, 1, max_level));
}


/**
 * _binary_tree_is_complete - Helper function to traverse a binary tree
 * using level-order traversal and check if the tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 * @level: The level of a binary tree to traverse.
 *
 * Return: Nothing.
 */
int _binary_tree_is_complete(const binary_tree_t *tree, size_t level, size_t max_level)
{
	if (!tree)
	{
		return (level >= max_level);
	}
	if (level >= max_level)
	{
		return (tree->parent->left &&!tree->left && !tree->right);
	}

	return ((_binary_tree_is_complete(tree->left, level + 1, max_level)) &&
		(_binary_tree_is_complete(tree->right, level + 1, max_level)));
}


/**
 * _binary_tree_height - Finds the height of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of a binary tree.
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (-1);
	}
	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);
	return (max(left_height, right_height) + 1);
}


/**
 * max - Finds the max number between two numbers
 *
 * @first: first number
 * @second: second number
 *
 * Return: the max number
 */
int max(int first, int second)
{
	if (first > second)
	{
		return (first);
	}
	else
	{
		return (second);
	}
}
