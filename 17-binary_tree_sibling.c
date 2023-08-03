#include "binary_trees.h"


/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: A pointer to the node to find the sibling
 *
 * Return: A pointer to the sibling node if it exist, otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent_node;

	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	parent_node = node->parent;
	if (parent_node->left == NULL || parent_node->right == NULL)
	{
		return (NULL);
	}
	if (parent_node->left == node)
	{
		return (parent_node->right);
	}
	return (parent_node->left);
}
