#include "binary_trees.h"

/**
 * binary_tree_depth - It determines a depth of the node in the binary tree.
 * @tree: A reference to the node that determines the depth.
 *
 * Return: Upon NULL, the process returns 0, otherwise returns depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
