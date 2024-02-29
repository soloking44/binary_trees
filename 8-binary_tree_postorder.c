#include "binary_trees.h"

/**
 * binary_tree_postorder - It navigates a binary tree applying post-orde.
 * @tree: A reference to the root node of the tree that traversed.
 * @func: A reference to a process that calls for every node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
