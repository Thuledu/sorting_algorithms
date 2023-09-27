#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);

/**
 * getMax - Get the maximum value in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum value
 */
int getMax(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countingSort - Sort an array using counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The current exponent
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};

	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int max = getMax(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
