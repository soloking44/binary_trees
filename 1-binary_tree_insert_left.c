#include "binary_trees.h"

/**
 * binary_tree_insert_left - It adds a node as a left-child of another node.
 *
 * @parent: A reference to the node to add the left child into.
 * @value: The data to save the new node.
 *
 * Return: A reference to the generated node, NULL if it fail.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
