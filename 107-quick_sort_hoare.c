#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int partition(int *array, int low, int high);
void quicksort(int *array, int low, int high);
void quick_sort_hoare(int *array, size_t size);

/**
 * partition - Partition the array using the Hoare partition scheme
 * @array: The array
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;

		print_array(array, high - low + 1);
	}
}

/**
 * quicksort - Recursive helper function for quick_sort_hoare
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 */
void quicksort(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quicksort(array, low, pi);
		quicksort(array, pi + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 * order using the Quick sort algorithm with the Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size - 1);
}
