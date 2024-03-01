#include "binary_trees.h"

/**
 * tree_size - Determines the total of heights in tree
 * @tree: Reference to the root node of the tree that determines
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - Arrange the Binary Max Heap
 * in order to array of numbers
 *
 * @heap: Reference to the root node in the heap
 * @size: An address to save the size of the array
 *
 * Return: Reference to array arranged in order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int x, *k = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	k = malloc(sizeof(int) * (*size));

	if (!k)
		return (NULL);

	for (x = 0; heap; x++)
		k[x] = heap_extract(&heap);

	return (k);
}
