#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * create_queue - Creates quere of binary trees
 *
 * @front: A pointer to the first index
 * @rear: A pointer to the index of the last item in the queue
 *
 * Return: A quere of binary trees.
 */
binary_tree_t **create_queue(int *front, int *rear)
{
	binary_tree_t **queue;

	queue = malloc(sizeof(binary_tree_t *) * MAX_Q_SIZE);
	*front = 0;
	*rear = 0;
	return (queue);
}

/**
 * push - Adds a binary tree to the queue
 *
 * @queue: the queue to add the binary tree
 * @rear: the index at which the binary tree is added
 * @tree: the binary tree to be queue
 *
 * Return: Nothing.
 */
void push(binary_tree_t **queue, int *rear, binary_tree_t *tree)
{
	queue[*rear] = tree;
	(*rear)++;
}

/**
 * pop - Removes a binary tree from the queue
 *
 * @queue: the queue remove the binary tree from
 * @front: the index of the binary tree to be removed
 *
 * Return: A pointer to the binary tree removed.
 */
binary_tree_t *pop(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 *
 * @tree: A pointer to the root of the binary tree
 * @func: A pointer to a function call for each node.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (func)(int))
{
	if (tree != NULL && func != NULL)
	{
		int front, rear;
		binary_tree_t **queue;
		binary_tree_t *root;

		queue = create_queue(&front, &rear);
		root = (binary_tree_t *)tree;

		while (root)
		{
			printf("%d\n", root->n);

			if (root->left)
			{
				push(queue, &rear, root->left);
			}
			if (root->right)
			{
				push(queue, &rear, root->right);
			}
			root = pop(queue, &front);
		}
		free(queue);
	}
}
