#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void shell_sort(int *array, size_t size);
int main(void);

/**
 * shell_sort - Sorts an array of integers in
 * ascending order using the Shell sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	/* Generate the Knuth sequence */
	int gap = 1;
	while (gap <= (int)size / 3)
	{
		gap = gap * 3 + 1;
	}

	/* Perform the Shell sort */
	while (gap > 0)
	{
		int i;
		for (i = gap; i < (int)size; i++)
		{
			int temp = array[i];
			int j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/* Print the array after each iteration */
		int j;
		for (j = 0; j < (int)size; j++)
		{
			printf("%d ", array[j]);
		}

		printf("\n");

		gap = (gap - 1) / 3;
	}
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int array[] = {9, 5, 7, 1, 3};
	size_t size = sizeof(array) / sizeof(array[0]);

	int i;
	for (i = 0; i < (int)size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	shell_sort(array, size);

	int j;
	for (j = 0; j < (int)size; j++)
	{
		printf("%d ", array[j]);
	}
	printf("\n");

	return (0);
}
