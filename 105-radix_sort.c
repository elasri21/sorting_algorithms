#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
* max_num - get the max number from an array
* @arr: array to work with
* @size: the size of array
* Return: integer
*/
int max_num(int *arr, int size)
{
int max_n, i;
for (max_n = arr[0], i = 1; i < size; i++)
{
if (arr[i] > max_n)
max_n = arr[i];
}
return (max_n);
}

/**
* sort_places - do the same job until the array gets sorted
* @arr: array to work with
* @size: the size of array
* @place: place
* @sorted: sorted array
* Return: Nothing
*/
void sort_places(int *arr, size_t size, int place, int *sorted)
{
int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t i;
for (i = 0; i < size; i++)
counter[(arr[i] / place) % 10] += 1;
for (i = 0; i < 10; i++)
counter[i] += counter[i - 1];
for (i = size - 1; (int)i >= 0; i--)
{
sorted[counter[(arr[i] / place) % 10] - 1] = arr[i];
counter[(arr[i] / place) % 10] -= 1;
}
for (i = 0; i < size; i++)
arr[i] = sorted[i];
}

/**
 * radix_sort - sorts an array with radix algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
int big, place, *sorted;
if (array == NULL || size < 2)
return;
sorted = (int *)malloc(sizeof(int) * size);
if (sorted == NULL)
return;
big = max_num(array, size);
for (place = 1; big / place > 0; place *= 10)
{
sort_places(array, size, place, sorted);
print_array(array, size);
}
free(sorted);
}
