#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t count, int dir);
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t count, int dir);
void bitonic_sort(int *array, size_t size);

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bitonic_merge - Merges two subarrays in a specific order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @start: Starting index of the subarray
 * @count: Number of elements to be merged
 * @dir: Sorting direction (UP or DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = start; i < start + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }

        bitonic_merge(array, size, start, k, dir);
        bitonic_merge(array, size, start + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursively performs bitonic sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @start: Starting index of the subarray
 * @count: Number of elements to be sorted
 * @dir: Sorting direction (UP or DOWN)
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        bitonic_sort_recursive(array, size, start, k, 1);
        bitonic_sort_recursive(array, size, start + k, k, 0);
        bitonic_merge(array, size, start, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, 0, size, 1);
}
