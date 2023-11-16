#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swapping - swaps two node in dll
 * @head: head of the list
 * @prev: previous node
 * @next: next node
 * Return: Nthing
 */

void swapping(listint_t **head, listint_t *prev, listint_t *next)
{
if (*head == NULL || prev == NULL || next == NULL)
return;
if (prev == next)
return;
if (prev->prev != NULL)
prev->prev->next = next;
else
*head = next;
if (next->next != NULL)
next->next->prev = prev;
prev->next = next->next;
next->prev = prev->prev;
next->next = prev;
prev->prev = next;
if (prev->next != NULL)
prev->next->prev = prev;
}
/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * @list: list to be sorted
 * Return:Nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *tmp, *node;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
tmp = (*list)->next;
while (tmp != NULL)
{
node = tmp->prev;
while (node != NULL)
{
if (tmp->n < node->n)
{
swapping(list, node, tmp);
print_list((const listint_t *)*list);
}
node = node->prev;
}
tmp = tmp->next;
}
}
