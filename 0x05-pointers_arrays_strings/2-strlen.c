#include "main.h"
/**
 * _strlen -  finds and prints the lengths of strings.
 * @s: pointer to string.
 *
 * Return: length of strings.
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
