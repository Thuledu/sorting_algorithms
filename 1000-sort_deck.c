#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2);
void sort_deck(deck_node_t **deck);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @deck: Pointer to the deck of cards
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev)
		node2->prev->next = node1;
	if (node1->next)
		node1->next->prev = node2;

	if (*deck == node1)
		*deck = node2;
	else if (*deck == node2)
		*deck = node1;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Double pointer to the deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *ptr1 = *deck;
	deck_node_t *lptr = NULL;

	if (*deck == NULL)
		return;

	do {
		swapped = 0;
		ptr1 = *deck;

		while (ptr1->next != lptr)
		{
			if (ptr1->card->kind > ptr1->next->card->kind ||
					(ptr1->card->kind == ptr1->next->card->kind &&
					 strcmp(ptr1->card->value, ptr1->next->card->value) > 0))
			{
				swap_nodes(deck, ptr1, ptr1->next);
				swapped = 1;
			}
			else
			{
				ptr1 = ptr1->next;
			}
		}

		lptr = ptr1;
	} while (swapped);
}
