#include "binary_trees.h"


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



/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 *
 * @tree: A pointer to the root node of the tree to count the number of leaves
 *
 * Return: Number of leaves in a binary tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	else
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}



/**
 * binary_tree_nodes - Counts the nodes with at least one child in a binary tree
 *
 * @tree: A pointer to the root node of the tree to count the number of leaves
 *
 * Return: Number of leaves in a binary tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
		return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

