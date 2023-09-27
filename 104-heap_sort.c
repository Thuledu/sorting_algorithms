#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void sift_down(int *array, size_t start, size_t end, size_t size);
void heap_sort(int *array, size_t size);

/**
 * sift_down - Performs the sift-down operation on a heap
 * @array: The array representing the heap
 * @start: The starting index of the subtree
 * @end: The ending index of the subtree
 * @size: The size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while (root * 2 + 1 <= end)
	{
		size_t child = root * 2 + 1;
		size_t swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
		{

			return;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	for (size_t i = size / 2 - 1; i > 0; i--)
		sift_down(array, i, size - 1, size);

	for (size_t i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
