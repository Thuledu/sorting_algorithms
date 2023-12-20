#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare function for qsort
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 * Return: Integer value based on the comparison
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = ((const deck_node_t *)card1)->card;
    const card_t *c2 = ((const deck_node_t *)card2)->card;

    if (c1->kind != c2->kind)
        return (c1->kind - c2->kind);
    else
        return (strcmp(c1->value, c2->value));
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t count = 0, i;
    deck_node_t *current = *deck;
    deck_node_t **nodes = NULL;

    if (deck == NULL || *deck == NULL)
        return;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    nodes = malloc(sizeof(deck_node_t *) * count);
    if (nodes == NULL)
        return;

    current = *deck;
    for (i = 0; i < count; i++)
    {
        nodes[i] = current;
        current = current->next;
    }

    qsort(nodes, count, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < count; i++)
    {
        if (i == 0)
            nodes[i]->prev = NULL;
        else
            nodes[i]->prev = nodes[i - 1];

        if (i == count - 1)
            nodes[i]->next = NULL;
        else
            nodes[i]->next = nodes[i + 1];
    }

    *deck = nodes[0];
    free(nodes);
}
