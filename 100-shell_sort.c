#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort algorithm
 * @array: the array
 * @size: the size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;
int tmp;
gap = 1;
if (array == NULL || size < 2)
return;
while (gap <= size / 3)
gap = gap * 3 + 1;

while (gap > 0)
{
for (i = gap; i < size; i++)
{
tmp = array[i];
for (j = i;j >= gap && array[j - gap] > tmp; j -= gap)
{
array[j] = array[j - gap];
}
array[j] = tmp;
}
print_array(array, size);
gap = (gap - 1) / 3;
}
}
