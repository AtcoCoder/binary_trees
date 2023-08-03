#include "binary_trees.h"
#include <stdio.h>

/**
 * max - Checks for the max number between two numbers
 *
 * @first: first number
 * @second: second number
 *
 * Return: the Max number.
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


/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of a binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);
	return (left_height - right_height);
}
