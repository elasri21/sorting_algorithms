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
int  max_num(int *arr, size_t size)
{
size_t i;
int max_num;
for (max_num = arr[0], i = 1; i < size; i++)
{
if (arr[i] > max_num)
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
count_arr = (int *)malloc(sizeof(int) * (new_size + 1));
if (count_arr == NULL)
return;
sorted_arr = (int *)malloc(sizeof(int) * size);
if (sorted_arr == NULL)
{
free(count_arr);
return;
}
for (i = 0; i <= new_size; i++)
count_arr[i] = 0;
for (i = 0; i < size; i++)
count_arr[array[i]] += 1;
for (i = 0, j = 1; j <= new_size; i++, j++)
count_arr[j] = count_arr[j] + count_arr[i];
print_array((const int *)count_arr, new_size + 1);
for (i = 0; i < size; i++)
{
sorted_arr[count_arr[array[i]] - 1] = array[i];
count_arr[array[i]] -= 1;
}
for (i = 0; i < size; i++)
array[i] = sorted_arr[i];
free(count_arr);
free(sorted_arr);
}
