#include <stdio.h>
#include "sort.h"

/**
 * swap_node - Swaps two nodes in a doubly linked list
 * @node: Node to be swapped
 * @list: Pointer to the head of the doubly linked list
 * Return: The new head of the list
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
    listint_t *prev, *next;

    if (node == NULL || *list == NULL)
        return (NULL);

    prev = node->prev;
    next = node->next;
    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    node->prev = prev ? prev->prev : NULL;
    node->next = prev ? prev : *list;
    if (prev == NULL)
        *list = node;
    else
        prev->prev = node;
    if (next)
        next->prev = prev;
    if (prev)
        prev->next = next;
    return (*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *ptr;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (ptr = *list; ptr->next != NULL; ptr = ptr->next)
        {
            if (ptr->n > ptr->next->n)
            {
                *list = swap_node(ptr, list);
                print_list(*list);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (ptr = ptr->prev; ptr->prev != NULL; ptr = ptr->prev)
        {
            if (ptr->n < ptr->prev->n)
            {
                *list = swap_node(ptr->prev, list);
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}
