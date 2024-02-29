#include "binary_trees.h"

/**
 * binary_tree_balance - It determines the balance factor of a binary tree.
 * @tree: A reference to the root node of the tree.
 *
 * Return: Always returns 0 upon NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - It determines the height of a binary tree.
 * @tree: A reference to the root node of the tree that determines height.
 *
 * Return: Always return 0 upon NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lef > rig) ? lef : rig);
	}
	return (0);
}
