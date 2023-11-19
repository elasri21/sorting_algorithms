#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * forward_swap - swaps nodes from head to tail
 * @list: the list to be sorted
 * @head: the head of the list
 * @blinder: the node that will traverse the list
 * Return: Nothing
 */
void forward_swap(listint_t **list, listint_t **head, listint_t **blinder)
{
listint_t *tmp;

tmp = (*blinder)->next;
if ((*blinder)->prev != NULL)
(*blinder)->prev->next = tmp;
else
*list = tmp;
tmp->prev = (*blinder)->prev;
(*blinder)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *blinder;
else
*head = *blinder;
(*blinder)->prev = tmp;
tmp->next = *blinder;
*blinder = tmp;
}

/**
 * backward_swap - swaps nodes from tail to head
 * @list: the list to be sorted
 * @tail: the tailof the list
 * @blinder: the node that will traverse the list
 * Return: Nothing
 */
void backward_swap(listint_t **list, listint_t **tail, listint_t **blinder)
{
listint_t *tmp;
tmp = (*blinder)->prev;
if ((*blinder)->next != NULL)
(*blinder)->next->prev = tmp;
else
*tail = tmp;
tmp->next = (*blinder)->next;
(*blinder)->prev = tmp->prev;
if (tmp->prev != NULL)
tmp->prev->next = *blinder;
else
*list = *blinder;
(*blinder)->next = tmp;
tmp->prev = *blinder;
*blinder = tmp;
}

/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail
 * @list: the list
 * Return:Nothing
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *blinder, *tail;
int test = 0;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
tail = *list;
while (tail->next != NULL)
tail = tail->next;
while (test == 0)
{
test = 1;
blinder = *list;
while (blinder != tail)
{
if (blinder->n > blinder->next->n)
{
forward_swap(list, &tail, &blinder);
print_list((const listint_t *)*list);
test = 0;
}
blinder = blinder->next;
}
blinder = blinder->prev;
while (blinder != *list)
{
if (blinder->n < blinder->prev->n)
{
backward_swap(list, &tail, &blinder);
print_list((const listint_t *)*list);
test = 0;
}
blinder = blinder->prev;
}
}
}
