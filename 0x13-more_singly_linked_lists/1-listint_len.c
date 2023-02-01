#include "lists.h"
/**
 * listint_len - returns the number of elemsnts in list.
 * @h: pointer to the list.
 * Return: number of elements in the list.
*/
size_t listint_len(const listint_t *h)
{
	size_t num;

	num = 0;
	while (h != NULL)
	{
	num++;
	h = h->next;
	}
	return (num);
}
