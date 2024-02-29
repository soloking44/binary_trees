#include "binary_trees.h"
#include "limits.h"

int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);

/**
 * is_avl_helper - It verifies whether a binary tree is a proper AVL tree.
 * @tree: A reference to the root node that verify the tree.
 * @lo: The data of the lowest node checked so far.
 * @hi: The data of the top node checked so far.
 *
 * Return: Return 1 if the tree is a valid AVL tree, else, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - It verifies whether a binary tree is a proper AVL tree.
 * @tree: A reference to the root node that verify a tree.
 *
 * Return: Return 1 if tree is an valid AVL tree, and else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * height - Determines a height of the binary tree.
 * @tree: A reference to the root node that determines the tree height.
 *
 * Return: If tree is NULL, the process will return 0, otherwise return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + height(tree->left) : 1;
		rig = tree->right ? 1 + height(tree->right) : 1;
		return ((lef > rig) ? lef : rig);
	}
	return (0);
}
