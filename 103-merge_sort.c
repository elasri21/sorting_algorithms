#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merger - merge sorted array
 * @arr: array
 * @sub_sorted: sorted array
 * @lb: louer bound
 * @ub: upper bound
 * @mid: index of the array middle element
 * Return: Nothing
 */
void merger(int *arr, int *sub_sorted, size_t lb, size_t mid, size_t ub)
{
size_t i, j, k = 0;
printf("Merging...\n[left]: ");
print_array(arr + lb, mid - lb);
printf("[right]: ");
print_array(arr + mid, ub - mid);
for (i = lb, j = mid; i < mid && j < ub; k++)
{
sub_sorted[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
}
for (; i < mid; i++)
sub_sorted[k++] = arr[i];
for (; j < ub; j++)
sub_sorted[k++] = arr[j];
for (i = lb, j = 0; i < ub; i++)
arr[i] = sub_sorted[j++];
printf("[Done]: ");
print_array(arr + lb, ub - lb);
}

/**
 * do_it_again - repeat same task
 * @arr: array
 * @sub_sorted: sorted array
 * @lb: louer bound
 * @ub: upper bound
 * Return: Nothing
 */
void do_it_again(int *arr, int *sub_sorted, size_t lb, size_t ub)
{
size_t mid;
if (ub > lb + 1)
{
mid = lb + (ub - lb) / 2;
do_it_again(arr, sub_sorted, lb, mid);
do_it_again(arr, sub_sorted, mid, ub);
merger(arr, sub_sorted, lb, mid, ub);
}
}

/**
 * merge_sort - sort an array using merge sort
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
int *sub_sorted;
if (array == NULL || size < 2)
return;
sub_sorted = (int *)malloc(sizeof(int) * size);
if (sub_sorted == NULL)
return;
do_it_again(array, sub_sorted, 0, size);
free(sub_sorted);
}
