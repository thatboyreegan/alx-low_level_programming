#include "lists.h"
/**
 * print_listint - prints all the elements of a linked list.
 * @h: pointer to list.
 * Return: number of nodes in the list.
*/
size_t print_listint(const listint_t *h)
{
	size_t nodes;

	nodes = 0;
	while (h != NULL)
	{
	printf("%d\n", h->n);
	nodes++;
	h  = h->next;
	}
	return (nodes);
}
