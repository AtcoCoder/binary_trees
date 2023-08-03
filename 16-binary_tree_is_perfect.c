#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (_binary_tree_is_perfect(tree));
}


/**
 * _binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int _binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (!((tree->left) && (tree->right)) &&
			!(!(tree->left) && !(tree->right)))
	{
		return (0);
	}

	if (_binary_tree_height(tree->left) != _binary_tree_height(tree->right))
	{
		return (0);
	}

	if (_binary_tree_is_perfect(tree->left) &&
			_binary_tree_is_perfect(tree->right))
	{
		return (1);
	}
	return (0);
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
