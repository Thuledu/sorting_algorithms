#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	do{
		swapped = 0;
		for (current = *list; current->next != NULL;
				current = current->next)
		{
			if (current->n > current->next->n)
			{
				/* Swap nodes */
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*list = current->next;

				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;

				if (current->next != NULL)
					current->next->prev = current;

				current->prev->next = current;
				swapped = 1;

				/* Print the list after each swap */
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		swapped = 0;
		for (current = current->prev; current->prev != NULL;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				/* Swap nodes */
				if (current->next != NULL)
					current->next->prev = current->prev;
				else
					current->prev->next = NULL;

				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = current->prev->prev;

				if (current->prev != NULL)
					current->prev->next = current;

				current->next->prev = current;
				swapped = 1;

				/* Print the list after each swap */
				print_list(*list);
			}
		}
	}while (swapped);
}
