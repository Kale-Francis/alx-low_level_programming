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

int advanced_binary_helper(int *array, int left, int right, int value)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    // Print the current subarray
    print_array(array, left, right);

    // If the middle element is the value, we check if it is the first occurrence
    if (array[mid] == value)
    {
        // Check if it's the first occurrence (by checking left element)
        if (mid == left || array[mid - 1] != value)
            return mid;
        // If not the first occurrence, continue searching in the left subarray
        return advanced_binary_helper(array, left, mid - 1, value);
    }
    else if (array[mid] < value)
    {
        return advanced_binary_helper(array, mid + 1, right, value);
    }
    else
    {
        return advanced_binary_helper(array, left, mid - 1, value);
    }
}

int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    return advanced_binary_helper(array, 0, size - 1, value);
}

int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
