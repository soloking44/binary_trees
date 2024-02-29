#include "binary_trees.h"

void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);

/**
 * pop - Removes the element from  a queue levelorder_queue_t.
 * @head: A reference to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Verifies if a tree meets a need to be complete.
 * @tree: A reference to the root node of the tree for traversal.
 *
 * Return: Always 0 if tree is NULL.
 *         Else, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}

/**
 * push - It adds a node to the end of a queue levelorder_queue_t.
 * @node: A binary tree node that display and add to queue.
 * @head: A reference to the initial of the queue.
 * @tail: A reference to the tail of the queue.
 *
 * Description: If malloc fails, exits the status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * create_node - Generates a fresh node for a levelorder_queue_t.
 * @node: The structure of binary tree node to be held by the fresh node.
 *
 * Return: Upon error, NULL.
 *         Else, reference to the fresh node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - It clears a levelorder_queue_t queue.
 * @head: A reference to the initial of a queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
