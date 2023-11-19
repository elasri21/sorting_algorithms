#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stddef.h>

/**
 * counting_sort - sorts an array using counting sort
 * @array: array to be sorted
 * @size: size of the array
 * Return:Nothing
 */

void counting_sort(int *array, size_t size)
{
size_t i, j, new_size = array[0], *new_arr, *count_arr;
int *sorted_arr;
for (i = 0; i < size; i++)
{
if ((size_t)array[i] > new_size)
new_size = array[i];
}
new_arr = (size_t *)malloc(sizeof(size_t) * (new_size + 1));
for (i = 0; i <= new_size; i++)
new_arr[i] = i;
count_arr = (size_t *)malloc(sizeof(size_t) * (new_size + 1));
for (i = 0; i <= new_size; i++)
count_arr[i] = 0;
for (i = 0; i <= new_size; i++)
{
for (j = 0; j < size; j++)
{
if ((size_t)array[j] == i)
count_arr[i] = count_arr[i] + 1;
}
}
for (i = 0, j = 1; j <= new_size; i++, j++)
count_arr[j] = count_arr[j] + count_arr[i];
print_array((const int *)count_arr, new_size + 1);
sorted_arr = (int *)malloc(sizeof(int) * size);
for (i = 0; i < size; i++)
{
for (j = 0; j <= new_size + 1; j++)
{
if ((size_t)array[i] == j + 1)
{
sorted_arr[count_arr[j]] = array[i];
count_arr[j] = count_arr[j] - 1;
}
}
}
for (i = 0; i < size; i++)
array[i] = sorted_arr[i];
free(new_arr);
free(count_arr);
free(sorted_arr);
}
