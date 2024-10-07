#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array using Linear search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where the value is located, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
    unsigned int i;

    if (array == NULL)
        return (-1);

    for (i = 0; i < size; i++)
    {
        printf("Value checked array[%u] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (i);
    }

    return (-1);
}
