#include "binary_trees.h"

/**
 * array_to_heap - Creates a Max Binary Heap tree within array
 * @array: Reference to the initial factors of the array
 * @size: The value of factor in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
