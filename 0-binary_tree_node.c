#include "binary_trees.h"

/**
 * binary_tree_node - This generates a custom binary tree node.
 * @parent: A reference to the nodes parent to be generated.
 * @value: The value intended for insertion into the new node.
 *
 * Return: Upon faliure - NULL.
 *         Else - a reference to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
