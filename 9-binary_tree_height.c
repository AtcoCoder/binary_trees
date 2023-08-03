#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of a binary tree, 0 if tree is empty.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (_binary_tree_height(tree));
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
