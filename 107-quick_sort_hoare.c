#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swapping - swaps two integers
 * @n1: first integer
 * @n2: second integer
 * Return: Nothing
 */
void swapping(int *n1, int *n2)
{
int tmp = *n1;
*n1 = *n2;
*n2 = tmp;
}
/**
 * portion - sorts a portion of the array
 * @arr: the array to be sorted
 * @size: the size of the array
 * @lb: louer bound
 * @ub: upper bound
 * Return: integer
 */
int portion(int *arr, size_t size, int lb, int ub)
{
int pvt, i, j;
pvt = arr[ub];
for (i = lb - 1, j = ub + 1; i < j;)
{
do {
i++;
} while (arr[i] < pvt);
do {
j--;
} while (arr[j] > pvt);
if (i < j)
{
swapping(arr + i, arr + j);
print_array(arr, size);
}
}
return (i);
}

/**
 * quick - sorts a portion of array using quick sort
 * @arr: the array
 * @size: the size of the array
 * @lb: louer bound
 * @ub: upper bound
 * Return: Nothing
 */
void quick(int *arr, size_t size, int lb, int ub)
{
int sample;
if (ub > lb + 1)
{
sample = portion(arr, size, lb, ub);
quick(arr, size, lb, sample - 1);
quick(arr, size, sample, ub);
}
}

/**
 * quick_sort_hoare - sorts an array using quick sort hoare
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick(array, size, 0, size - 1);
}
