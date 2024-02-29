#include "binary_trees.h"

/**
 * is_full_recursive - It recursively verifies whether a binary tree is full.
 * @tree: A reference to the root node of the tree that verifies.
 *
 * Return: Return 0 if tree is NULL.
 *         Else, 1.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - It verifies whether a binary tree is full.
 * @tree: A reference to the root node of the tree that verifies.
 *
 * Return: Always return NULL or is not full - 0.
 *         Else - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
