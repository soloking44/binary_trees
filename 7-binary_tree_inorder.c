#include "binary_trees.h"

/**
 * binary_tree_inorder - It traverses a binary tree using in-order traversal.
 * @tree: A reference to the root node of the tree that traversed.
 * @func: A reference to a process that calls for every node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
