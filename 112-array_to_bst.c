#include "binary_trees.h"

/**
 * array_to_bst - It creates a binary search tree within array.
 * @array: A reference to the present head of the array that is changed.
 * @size: The value of heads in @array.
 *
 * Return: A reference to the root node of the generated BST, or NULL if fails.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
				break;
		}
		if (jndex == index)
		{
			if (bst_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
