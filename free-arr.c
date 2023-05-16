#include "shell_header.h"

/**
 * free_array - Frees a dynamically allocated array of strings
 *
 * @arr: The array to be freed
 */
void free_array(char **arr)
{
	int row;

	if (arr == NULL)
		return;
	/* Iterate through each element in the array */
	for (row = 0; arr[row]; row++)
	{
		free(arr[row]);
		arr[row] = NULL;
	}
	free(arr);
	arr = NULL;
}
