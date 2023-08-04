#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node
 * of the two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	return (_binary_trees_ancestor(first, second, first, second));
}

/**
 * _binary_trees_ancestor_recursive - Helper function to find the lowest
 * common ancestor of two nodes recursively.
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * @original_first: A pointer to the original first node
 * (used to track the path)
 * @original_second: A pointer to the original second node
 * (used to track the path)
 *
 * Return: A pointer to the lowest common ancestor node
 * of the two given nodes.
 */
binary_tree_t *_binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second,
		const binary_tree_t *original_first,
		const binary_tree_t *original_second)
{
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	size_t first_depth = _binary_tree_depth(first);
	size_t second_depth = _binary_tree_depth(second);

	if (first_depth > second_depth)
	{
		return (_binary_trees_ancestor(first->parent, original_second,
					original_first, original_second));
	}
	else if (first_depth < second_depth)
	{
		return (_binary_trees_ancestor(original_first, second->parent,
					original_first, original_second));
	}

	return (_binary_trees_ancestor(first->parent, second->parent,
				original_first, original_second));
}

/**
 * _binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: A pointer to the node to measure the depth
 *
 * Return: The depth of a node in a binary tree.
 */
size_t _binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (_binary_tree_depth(tree->parent) + 1);
}
