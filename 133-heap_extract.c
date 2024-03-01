#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Determines the height within binary tree
 * @tree: Reference to the root node of the tree to determine
 *
 * Return: Always 0 or Hight upon NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);

	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}
/**
 * tree_size_h - Determines the total heights of tree
 * @tree: Reference to the root node of the tree to determine
 *
 * Return: Always 0 or Height upon NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_r = 1 + tree_size_h(tree->right);

	return (height_l + height_r);
}

/**
 * _preorder - Traverses a binary tree used pre-order method
 * @tree: Reference to a root node of a tree that traversed
 * @node: It serves as final note during traversal
 * @height: A height of the tree
 *
 * Return: Return nothing
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - Apply heapify for a max binary heap
 * @root: Reference to a binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - Removes the root node in a Max Binary Heap
 * @root: Reference to the heap root
 * Return: The data of removed node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);
}
