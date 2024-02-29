#include "binary_trees.h"

bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);

/**
 * bst_delete - Removes a node in a binary search tree.
 * @root: A reference to the root node within BST.
 * @node: A reference to the node that removes in the BST.
 *
 * Return: A reference to the fresh root node when deleted.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or exclusively right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* A left-child node only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* has 2 children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * inorder_successor - Retieves the lowest data within a binary search tree.
 * @root: A reference to the root BST node.
 *
 * Return: The small data within @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Deletes a node within the binary search tree.
 * @root: A reference to the root node of the BST that deletes a node.
 * @value: The data to delete within the BST.
 *
 * Return: A reference to the fresh root node when deleted.
 *
 * Description: If a node slated to be removed has 2 children, it
 *              can be changed with initial in-order.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

/**
 * bst_remove_recursive - Recursively deletes a node in a binary search tree.
 * @root: A reference to the root node of the BST that deletes a node.
 * @node: A reference to the present node in the BST.
 * @value: The data to deletes in the BST.
 *
 * Return: A reference to the root node when deleted.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}
