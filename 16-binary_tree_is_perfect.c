#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);

/**
 * is_leaf - It verifies whether a node is a leaf of a binary tree.
 * @node: A reference to the node that verifies.
 *
 * Return: Upon leaf, 1, Else, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - It outputs the depth of a specified
 *         node within a binary tree.
 * @tree: A reference to the node that determines the depth.
 *
 * Return: Return always the depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - It outputs the leaf of a binary tree.
 * @tree: A reference to the root node of a tree.
 *
 * Return: Always return the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - It recursively verifies that a binary tree is ideal.
 * @tree: A reference of the root node that verifies a tree.
 * @leaf_depth: Always returns the depth of one leaf.
 * @level: The position of present node.
 *
 * Return: When the tree is ideal, 1, else 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - It verifies whether a binary tree is ideal.
 * @tree: A reference to the root node that verifies a tree.
 *
 * Return: Upon NULL or not ideal, 0.
 *         Else, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
