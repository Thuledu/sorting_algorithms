#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b);
int partition(int *array, int low, int high);
void quick_sort_recursive(int *array, int low, int high);
void quick_sort(int *array, size_t size);

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Lomuto partition scheme for Quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 * Return: Index of the pivot element.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	
	int j;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quick_sort_recursive(array, low, pi - 1);
		quick_sort_recursive(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1);
}

