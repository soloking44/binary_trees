#include "binary_trees.h"

/**
 * binary_tree_is_leaf - It tests if a node is a leaf.
 * @node: A reference to the node to test for.
 *
 * Return: When the node is a leaf - 1.
 *         Else - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
