#include <stdlib.h>
#include <stdio.h>
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
 * merging - sorts and merge a portion of array
 * @arr: array to be sorted
 * @size: the size of array
 * @beg: the starting point
 * @portion: the portion to be sorted
 * @dir: the direction
 * Return: Nothing
 */
void merging(int *arr, size_t size, size_t beg, size_t portion, char dir)
{
size_t j, step;
step = portion / 2;
if (portion > 1)
{
for (j = beg; j < beg + step; j++)
{
if ((dir == TOP && arr[j] > arr[j + step]) ||
(dir == BOTTOM && arr[j] < arr[j + step]))
swapping(arr + j, arr + j + step);
}
merging(arr, size, beg, step, dir);
merging(arr, size, beg + step, step, dir);
}
}

/**
 * convertor - take an array and converts it to a portion
 * @arr: the array to work with
 * @size: the size of the array
 * @beg: the starting point
 * @portion: the portion to be sorted
 * @dir: direction of the sotring
 * Return: Nothing
 */
void convertor(int *arr, size_t size, size_t beg, size_t portion, char dir)
{
size_t step = portion / 2;
char *dir_name = (dir == TOP) ? "TOP" : "BOTTOM";
if (portion > 1)
{
printf("Merging [%lu/%lu] (%s):\n", portion, size, dir_name);
print_array(arr + beg, portion);
convertor(arr, size, beg, step, TOP);
convertor(arr, size, beg + step, step, BOTTOM);
merging(arr, size, beg, portion, dir);
printf("Result [%lu/%lu] (%s):\n", portion, size, dir_name);
print_array(arr + beg, portion);
}
}

/**
 * bitonic_sort - sorts an array using bitonic sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
convertor(array, size, 0, size, TOP);
}
