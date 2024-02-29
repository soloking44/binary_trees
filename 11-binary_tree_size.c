#include "binary_trees.h"

/**
 * binary_tree_size - It determines the size of a binary tree.
 * @tree: A reference to the root node of the tree that determines the size.
 *
 * Return: Returns the size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
