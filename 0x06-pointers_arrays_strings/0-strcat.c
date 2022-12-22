#include "main.h"
/**
 * _strcat - contanates two strings.
 * @dest: pointer to destination.
 * @src: pointer to source.
 * Return: destination of string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
