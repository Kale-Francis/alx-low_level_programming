#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *node = list;

    if (!list)
        return (NULL);

    /* Traverse using the express lane */
    while (node->express && node->express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->express->index, node->express->n);
        node = node->express;
    }

    /* If we've found a range, check the values between node and node->express */
    printf("Value found between indexes [%lu] and [%lu]\n", node->index, node->express ? node->express->index : node->index);

    /* Now perform a linear search between node and node->express */
    while (node)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        if (node->n == value)
            return (node);
        if (node->express == NULL)  /* Reached the end of the list */
            break;
        node = node->next;
    }

    return (NULL);
}

/* Helper functions for creating, printing, and freeing the skip list */

skiplist_t *create_skiplist(int *array, size_t size)
{
    skiplist_t *head = NULL, *temp = NULL;
    skiplist_t *express_node = NULL;
    size_t i;

    for (i = 0; i < size; i++)
    {
        temp = malloc(sizeof(skiplist_t));
        if (!temp)
            return NULL;
        temp->n = array[i];
        temp->index = i;
        temp->next = head;
        temp->express = express_node;  /* Link the express node */
        head = temp;

        if (i % (size / (size > 1 ? sqrt(size) : 1)) == 0)  /* Express lane */
            express_node = temp;
    }

    return head;
}

void print_skiplist(const skiplist_t *list)
{
    while (list)
    {
        printf("Index[%lu] = [%d]\n", list->index, list->n);
        list = list->next;
    }
}

void free_skiplist(skiplist_t *list)
{
    skiplist_t *temp;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}
