#include "binary_trees.h"

/**
 * bst_search - It looks for a data in a binary tree.
 * @tree: A reference to the root node BST to locate.
 * @value: The data to locate in BST.
 *
 * Return: Upon NULL or the data is not found, NULL.
 *         else, reference to the node held by the data.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
