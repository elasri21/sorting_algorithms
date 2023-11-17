#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
size_t i, j, min_idx;
int tmp;
for (i = 0; i < size - 1; i++)
{
min_idx = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_idx])
min_idx = j;
}
tmp = array[i];
array[i] = array[min_idx];
array[min_idx] = tmp;
if (i != min_idx)
print_array(array, size);
}
}
