#include <stdio.h>
#include "sort.h"

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
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1, j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (array[i + 1] > array[high])
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * lomuto_quick_sort - Recursive function to perform Quick sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void lomuto_quick_sort(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, size, low, high);

        lomuto_quick_sort(array, size, low, pi - 1);
        lomuto_quick_sort(array, size, pi + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_quick_sort(array, size, 0, size - 1);
}
