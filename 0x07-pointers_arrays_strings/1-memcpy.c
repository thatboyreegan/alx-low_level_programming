#include "main.h"
/**
 * _memcpy - copies memory area.
 * @dest: destination memory
 * @src: source memory
 * @n: bytes filled
 *
 * Return: the pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + 1) = *(src + i);

	return (dest);
}
