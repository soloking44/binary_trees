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
	size_t x, m;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; m++)
	{
		for (m = 0; m < x; m++)
		{
			if (array[m] == array[x])
				break;
		}
		if (m == x)
		{
			if (avl_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
