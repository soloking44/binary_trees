#include "binary_trees.h"
#include "limits.h"

int is_bst_helper(const binary_tree_t *tree, int low, int high);
int binary_tree_is_bst(const binary_tree_t *tree);
/**
 * is_bst_helper - Verifies whether a binary tree is proper.
 * @tree: A reference to the root node of the tree to verify.
 * @lo: The data of the least node checked so far.
 * @hi: The data of the highest node checked so far.
 *
 * Return: Always return 1 if tree is a valid BST, else, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Verifies whether a binary tree is proper.
 * @tree: A reference to the root node of the tree to verify.
 *
 * Return: Return 1 if tree is a valid BST, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
