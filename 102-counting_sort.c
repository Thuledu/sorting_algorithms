#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *sorted_array;
	int max_value = 0, i, j;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Allocate memory for the counting array */
	counting_array = malloc(sizeof(int) * (max_value + 1));
	if (counting_array == NULL)
		return;

	/* Initialize the counting array with 0s */
	for (i = 0; i <= max_value; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each value in the array */
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]]++;

	/* Update the counting array to store the starting position of each value */
	for (i = 1; i <= max_value; i++)
		counting_array[i] += counting_array[i - 1];

	/* Allocate memory for the sorted array */
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(counting_array);
		return;
	}

	/* Build the sorted array using the counting array */
	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	/* Free dynamically allocated memory */
	free(counting_array);
	free(sorted_array);

	/* Print the counting array */
	for (j = 0; j <= max_value; j++)
	{
		if (j != max_value)
			printf("%d, ", counting_array[j]);
		else
			printf("%d\n", counting_array[j]);
	}
}
