#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array using Jump Search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step, prev, i;

    if (array == NULL || size == 0)
        return (-1);

    step = sqrt(size);
    prev = 0;

    while (prev < size && array[prev] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        prev += step;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);
    prev -= step;

    for (i = prev; i < size && i <= prev + step; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return (i);
    }

    return (-1);
}
