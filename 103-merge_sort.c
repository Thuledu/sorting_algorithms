#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, int *left, int *right, size_t size);
void merge_sort(int *array, size_t size);

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: The left subarray
 * @mid: The middle index
 * @right: The right subarray
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	size_t left_size = size / 2;
	size_t right_size = size - left_size;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	size_t mid = size / 2;
	size_t left_size = mid;
	size_t right_size = size - mid;
	int *left = array;
	int *right = array + mid;

	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, left, right, size);
}

