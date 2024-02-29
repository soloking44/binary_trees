#include "binary_trees.h"

/**
 * binary_tree_uncle - It locates the uncle of a node
 *                     within a binary tree.
 * @node: A reference to the node that locates the uncle.
 *
 * Return: Upon NULL or dont have uncle, NULL.
 *         else, reference to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
