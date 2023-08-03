#include "binary_trees.h"


/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (_binary_tree_is_full(tree));
}

/**
 * _binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, otherwise 0.
 */
int _binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (1);
	}
	if ((tree->left == NULL && tree->right == NULL))
	{
		return (1);
	}
	if ((tree->left) && (tree->right))
	{
		if (_binary_tree_is_full(tree->left) && _binary_tree_is_full(tree->right))
		{
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
