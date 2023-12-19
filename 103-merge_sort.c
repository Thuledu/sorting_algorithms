#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: Pointer to the array to be sorted
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 * @size_l: Size of the left subarray
 * @size_r: Size of the right subarray
 */
void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc(sizeof(int) * (size_l + size_r));

    if (temp == NULL)
        return;

    printf("Merging...\n[left]: ");
    print_array(left, size_l);
    printf("[right]: ");
    print_array(right, size_r);

    while (i < size_l && j < size_r)
    {
        if (left[i] <= right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < size_l)
        temp[k++] = left[i++];

    while (j < size_r)
        temp[k++] = right[j++];

    for (i = 0; i < size_l + size_r; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array, size_l + size_r);

    free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid;
    int *left, *right;

    if (array == NULL || size < 2)
        return;

    if (size > 1)
    {
        mid = size / 2;
        left = array;
        right = array + mid;

        merge_sort(left, mid);
        merge_sort(right, size - mid);

        merge(array, left, right, mid, size - mid);
    }
}
