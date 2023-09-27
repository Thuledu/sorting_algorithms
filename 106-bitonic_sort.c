#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bitonic_merge(int *array, size_t low, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir);
void bitonic_sort(int *array, size_t size);

/**
 * bitonic_merge - Merge two subarrays of an array in a bitonic manner
 * @array: The array
 * @low: The starting index of the first subarray
 * @count: The number of elements to be sorted in each subarray
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		for (size_t i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursive helper function for bitonic_sort
 * @array: The array to be sorted
 * @low: The starting index of the subarray to be sorted
 * @count: The number of elements to be sorted
 * @dir: The direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
