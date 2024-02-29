#include "binary_trees.h"

/**
 * array_to_avl - It constructs an AVL tree within an array.
 * @array: A reference to the initial attributes of the array.
 * @size: The value of attributes in @array.
 *
 * Return: A reference to the root node generated AVL, or NULL if it fails.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; j++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
