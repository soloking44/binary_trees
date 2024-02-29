#include "binary_trees.h"

/**
 * binary_tree_nodes - It catculates the nodes have at least one child in a binary tree.
 * @tree: A reference to the root node of the tree that calculate the nodes.
 *
 * Return: Upon NULL, the process returns 0, otherwise returns node.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
