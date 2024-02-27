#include "binary_trees.h"

/**
 * binary_tree_is_root - It tests if the node is a root.
 * @node: A reference to the node to test for.
 *
 * Return: When the node is a root - 1.
 *         Else - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
