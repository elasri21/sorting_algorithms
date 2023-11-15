#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int tmp1, tmp2;
for (i = 0; i < size; i++)
{
for (j = 0; j < size; j += 1)
{
if (j + 1 < size)
{
tmp1 = array[j];
tmp2 = array[j + 1];
if (tmp1 > tmp2)
{
array[j] = tmp2;
array[j + 1] = tmp1;
print_array(array, size);
}
}
}
}
return;
}
