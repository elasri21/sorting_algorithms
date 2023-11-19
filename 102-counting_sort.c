#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stddef.h>

/**
 * max_num - get max element in an array
 * @arr: the array
 * @size: array size
 * Return: the max number in an array
 */
size_t max_num(int *arr, size_t size)
{
size_t i, max_num;
if (arr == NULL)
return (0);
max_num = arr[0];
for (i = 0; i < size; i++)
{
if ((size_t)arr[i] > max_num)
max_num = arr[i];
}
return (max_num);
}
/**
 * counting_sort - sorts an array using counting sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
size_t i, j, new_size;
int *count_arr, *sorted_arr;
if (array == NULL || size < 2)
return;
new_size = max_num(array, size);
if (new_size == 0)
return;
count_arr = (int *)malloc(sizeof(int) * (new_size + 1));
if (count_arr == NULL)
return;
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
if (sorted_arr == NULL)
return;
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
free(count_arr);
free(sorted_arr);
}
