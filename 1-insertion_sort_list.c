#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order using Insertion sort
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;

		while (next != NULL && next->n < current->n)
		{
			current->next = next->next;
			next->prev = current->prev;

			if (current->prev != NULL)
				current->prev->next = next;
			else
				*list = next;

			next->next = current;
			current->prev = next;

			next = current->next;
		}
		current = current->next;
	}
}
