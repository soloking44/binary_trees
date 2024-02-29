#include "binary_trees.h"

/**
 * binary_tree_height - It determines the height of a binary tree.
 * @tree: A reference to the root node of the tree that determines the height.
 *
 * Return: Unpon NULL, the process returns 0, otherwise returns height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((lef > rig) ? lef : rig);
	}
	return (0);
}
