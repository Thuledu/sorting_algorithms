#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array;
    size_t i, max = 0;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        if ((size_t)array[i] > max)
            max = array[i];
    }

    count_array = malloc(sizeof(int) * (max + 1));
    if (count_array == NULL)
        return;

    for (i = 0; i <= max; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    for (i = 1; i <= max; i++)
        count_array[i] += count_array[i - 1];

    print_array(count_array, max + 1);

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
    {
        free(count_array);
        return;
    }

    for (i = 0; i < size; i++)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = sorted_array[i];

    free(count_array);
    free(sorted_array);
}
