#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swapping - swaps two elements of an array
 * @n1: address of first element
 * @n2: address of second element
 * Return:Nothing
 */
void swapping(int *n1, int *n2)
{
int tmp = *n1;
*n1 = *n2;
*n2 = tmp;
}


/**
 * heapping - make a heap
 * @arr: array to be heapped
 * @size: size of the array
 * @b: the base
 * @i: the root
 * Return: Nothing
 */
void heapping(int *arr, size_t size, size_t b, size_t i)
{
size_t lb = 2 * i + 1;
size_t ub = 2 * i + 2;
size_t largest = i;
if (lb < b && arr[lb] > arr[largest])
largest = lb;
if (ub < b && arr[ub] > arr[largest])
largest = ub;
if (largest != i)
{
swapping(arr + i, arr + largest);
print_array(arr, size);
heapping(arr, size, b, largest);
}
}

/**
 * heap_sort - sorts an array using heap sort
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
int i;
if (array == NULL || size < 2)
return;
for (i = (size / 2) - 1; i >= 0; i--)
heapping(array, size, size, i);
for (i = size - 1; i >= 0; i--)
{
swapping(array, array + i);
print_array(array, size);
heapping(array, size, i, 0);
}
}
