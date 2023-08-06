#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_levelorder - Traverses through a binary tree
 * using level-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, height;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	height = _binary_tree_height(tree);

	for (level = 1; level <= height; level++)
	{
		_binary_tree_levelorder(tree, func, level);
	}
}


/**
 * _binary_tree_levelorder - Helper function to traverse a binary tree
 * using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * @level: The level of a binary tree to traverse.
 *
 * Return: Nothing.
 */
void _binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int),
		size_t level)
{
	if (tree == NULL)
	{
		return;
	}
	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		_binary_tree_levelorder(tree->left, func, level - 1);
		_binary_tree_levelorder(tree->right, func, level - 1);
	}
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
