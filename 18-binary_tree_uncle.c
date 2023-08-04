#include "binary_trees.h"


/**
 * binary_tree_uncle - Finds the uncle of a node
 *
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node if it exist, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent_node;
	binary_tree_t *grandpa;
	binary_tree_t *uncle;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}
	parent_node = node->parent;
	grandpa = parent_node->parent;
	uncle = NULL;

	if (grandpa->left == NULL || grandpa->right == NULL)
	{
		return (uncle);
	}
	if (grandpa->left == parent_node)
	{
		uncle = grandpa->right;
	}
	else
	{
		uncle = grandpa->left;
	}
	return (uncle);
}
