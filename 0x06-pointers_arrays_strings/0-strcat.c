#include "main.h"
/**
 * _strcat - contanates two strings.
 * @dest: pointer to a char.
 * @src: pointer to a char.
 * Return: dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		dest++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
