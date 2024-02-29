#include "binary_trees.h"

/**
 * binary_tree_sibling - It locates the sibling of a
 *                       node within a binary tree.
 * @node: A reference to the node that locate the sibling.
 *
 * Return: Upon NULL or there is no sibling - NULL.
 *         Else - reference to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
