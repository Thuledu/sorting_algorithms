#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Get the maximum value in an array
 * @array: Pointer to the array
 * @size: Size of the array
 * Return: The maximum value in the array
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * countSort - Perform counting sort based on the digit represented by exp
 * @array: Pointer to the array
 * @size: Size of the array
 * @exp: The exponent representing the significant digit
 */
void countSort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the Radix sort algorithm (LSD)
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = getMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
        countSort(array, size, exp);
}
