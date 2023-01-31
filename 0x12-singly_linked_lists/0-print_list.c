#include "lists.h"
/**
 * print_list - prints all elements of a list.
 * @h: singly linked list.
 * Return: number of elements in the list.
 */
size_t print_list(const list_t *h)
{
	size_t num;

	num = 0;
	if (!h)
		return (num);

	while (h)
	{
		if (h->str)
			printf("[%u] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");

		num++;
		h = h->next;
	}
	return (num);
}
