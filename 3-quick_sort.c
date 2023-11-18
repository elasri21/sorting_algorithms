#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * swapping - swap two elements in an array
 * @prev: previous element
 * @next: next element
 * Return: Nothing
 */

void swapping(int *prev, int *next)
{
int tmp = *prev;
*prev = *next;
*next = tmp;
}

/**
 * portion - looks for a right position
 * @array: the array to work with
 * @size: the size of the array
 * @lb: the lower bound
 * @ub: the upper bound
 * Return: integer position
 */
size_t portion(int *array, size_t size, int lb, int ub)
{
int i, j;
int pivot;
pivot = array[ub];
for (i = j = lb; j < ub; j++)
{
if (array[j] < pivot)
{
if (i < j)
{
swapping(&array[j], &array[i]);
print_array(array, size);
}
i++;
}
}
if (array[i] > pivot)
{
swapping(&array[i], &array[ub]);
print_array(array, size);
}
return (i);
}

/**
 * do_it_again - do the same job
 * @array: the array
 * @size: the size of the array
 * @lb: lower bound
 * @ub: the upper bound
 * Return: Nothing
 */
void do_it_again(int *array, size_t size, int lb, int ub)
{
if (lb < ub)
{
size_t pos = portion(array, size, lb, ub);
do_it_again(array, size, lb, pos - 1);
do_it_again(array, size, pos + 1, ub);
}
}


/**
 * quick_sort - sorts an array of integers using the Quick sort algorithm
 * @array: array to be sorted
 * @size: the size of the array
 * Return: Nothing
 *
 */
void quick_sort(int *array, size_t size)
{
if (size < 2)
return;
do_it_again(array, size, 0, size - 1);
}
