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
size_t i, j;
int curr, tmp;
for (i = 0; i < size; i++)
{
curr = array[i];
for (j = i + 1; j < size; j++)
{
if (array[j] < curr)
{
tmp = array[j];
array[j] = curr;
curr = tmp;
}
}
print_array(array, size);
array[i] = curr;
}
}
