#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree
 *
 * @tree: A pointer to the roon node of the tree to delete
 *
 * Return: Nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		_binary_tree_delete(tree);
		free(tree);
	}
}

/**
 * _binary_tree_delete - Deletes every node in the binary tree
 *
 * @tree: A pointer to the root node of the tree to delete
 *
 * Return: Nothing.
 */
void _binary_tree_delete(binary_tree_t *tree)
{
	if (tree->left)
	{
		_binary_tree_delete(tree->left);
		free(tree->left);
	}
	if (tree->right)
	{
		_binary_tree_delete(tree->right);
		free(tree->right);
	}
}
