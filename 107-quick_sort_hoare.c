#include <stdio.h>
#include "sort.h"

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
 * hoare_partition - Partitions the array using the Hoare scheme
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * Return: Index of the pivot element after partitioning
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * hoare_quick_sort_recursive - Recursively performs quick sort using Hoare scheme
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 */
void hoare_quick_sort_recursive(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, size, low, high);

        hoare_quick_sort_recursive(array, size, low, pivot);
        hoare_quick_sort_recursive(array, size, pivot + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition scheme)
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    hoare_quick_sort_recursive(array, size, 0, size - 1);
}
