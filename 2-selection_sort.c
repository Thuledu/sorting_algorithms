#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void swap(int *a, int *b);
void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");

	selection_sort(array, n);

	printf("\n");
	print_array(array, n);

	return (0);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the Selection sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t min_index = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);

			for (size_t k = 0; k < size; k++)
			{
				printf("%d ", array[k]);
			}

			printf("\n");
		}
	}
}

void print_array(const int *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
