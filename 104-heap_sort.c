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
 * heapify - Ensures the heap property is maintained
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @i: Index of the current node
 * @n: Size of the heap
 */
void heapify(int *array, size_t size, size_t i, size_t n)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, size, largest, n);
    }
}


/**
 * heap_sort - Sorts an array of integers in ascending order
 *              using the Heap sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, size, 0, i);
    }
}
