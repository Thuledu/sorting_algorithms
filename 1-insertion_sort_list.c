#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @h: Pointer to the head of the list
 * @n1: Pointer to the first node
 * @n2: Pointer to the second node
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
    listint_t *prev, *next;

    prev = (*n1)->prev;
    next = n2->next;
    if (prev)
        prev->next = n2;
    else
        *h = n2;
    if (next)
        next->prev = *n1;
    n2->prev = prev;
    n2->next = *n1;
    (*n1)->prev = n2;
    (*n1)->next = next;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                        in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            swap_nodes(list, &temp->prev, temp);
            print_list(*list);
        }
        current = current->next;
    }
}
