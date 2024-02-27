#include "binary_trees.h"

/**
 * binary_tree_preorder - It traverses a binary tree using pre-order traversal.
 * @tree: A reference to the root node of the tree that is traversed.
 * @func: A reference to a process that calls for every node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
