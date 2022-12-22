#include "main.h"
/**
 * leet - encodes a string into 1337.
 * @c: pointer to string.
 *
 * Return: encoded string.
 */
char *leet(char *c)
{
	char *cp = c;
	char word[] = {'A', 'E', 'O', 'T', 'L'};
	int value[] = {4, 3, 0, 7, 1};
	unsigned int j;

	while (*c)
	{
		for (j = 0; j < sizeof(word) / sizeof(char); j++)
		{
			if (*c == word[j] || *c == word[j] + 32)
			{
				*c = 48 + value[j];
			}
		}
		c++;
	}
	return (cp);
}
