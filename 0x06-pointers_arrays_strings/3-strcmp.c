#include "main.h"
/**
 * _strcmp - compares two strings.
 * @s1: pointer to the first string.
 * @s2: pointer to the second string.
 *
 * Return: 0 if both are equal
 * less than 0 if one is less than the other
 * more than 0 if one is greater than the other.
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	j = s1[i] - s2[i];
	return (j);
}
