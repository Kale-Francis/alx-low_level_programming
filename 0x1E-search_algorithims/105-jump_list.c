#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list using Jump search
 * @list: Pointer to the head of the list
 * @size: Number of nodes in the list
 * @value: Value to search for
 * Return: Pointer to the node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    if (!list || size == 0)
        return (NULL);

    size_t step = sqrt(size);
    listint_t *prev = NULL, *curr = list;

    // Jump through the list in blocks of size step
    while (curr && curr->next && curr->n < value)
    {
        prev = curr;
        for (size_t i = 0; i < step && curr->next; i++)
            curr = curr->next;
        
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);

        if (curr->n >= value)
            break;
    }

    // Linear search for the value between prev and curr
    while (prev && prev->index <= curr->index)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);

        if (prev->n == value)
            return prev;
        prev = prev->next;
    }

    return NULL;
}

/* Helper functions for creating, printing, and freeing the list */

listint_t *create_list(int *array, size_t size)
{
    listint_t *head = NULL, *temp = NULL;
    for (size_t i = 0; i < size; i++)
    {
        temp = malloc(sizeof(listint_t));
        if (!temp)
            return NULL;
        temp->n = array[i];
        temp->index = i;
        temp->next = head;
        head = temp;
    }
    return head;
}

void print_list(const listint_t *list)
{
    while (list)
    {
        printf("Index[%lu] = [%d]\n", list->index, list->n);
        list = list->next;
    }
}

void free_list(listint_t *list)
{
    listint_t *temp;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}
