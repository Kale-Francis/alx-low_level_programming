#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int left, int right)
{
    printf("Searching in array: ");
    for (int i = left; i <= right; i++)
    {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

int binary_search(int *array, int left, int right, int value)
{
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        printf("Value checked array[%d] = [%d]\n", mid, array[mid]);
        
        if (array[mid] == value)
            return mid;
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int exponential_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    // Step 1: Find the range where the value could be
    if (array[0] == value)
        return 0;

    int i = 1;
    while (i < (int)size && array[i] <= value)
    {
        printf("Value checked array[%d] = [%d]\n", i, array[i]);
        i = i * 2;  // Exponential step
    }

    // Step 2: Print the range in which we are searching
    printf("Value found between indexes [%d] and [%d]\n", i / 2, i < (int)size ? i : (int)size - 1);

    // Step 3: Apply binary search in the found range
    return binary_search(array, i / 2, i < (int)size ? i : (int)size - 1, value);
}

int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 62, exponential_search(array, size, 62));
    printf("Found %d at index: %d\n\n", 3, exponential_search(array, size, 3));
    printf("Found %d at index: %d\n", 999, exponential_search(array, size, 999));
    return (EXIT_SUCCESS);
}
