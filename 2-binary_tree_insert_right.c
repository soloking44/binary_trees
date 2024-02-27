#include "binary_trees.h"

/**
 * binary_tree_insert_right - It adds a node to the right-child
 *                            of another node to a binary tree.
 * @parent: A referance to the node to add the right-child into.
 * @value: The data to save the new node.
 *
 *
 * Return: A reference to the node, NULL if it fail or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
