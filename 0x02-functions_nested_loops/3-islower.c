#include "main.h"
/**
 * _islower - Checks for lowercase character.
 *
 * Return: Always 0.
 */
int _islower(int c)
{
	if (c > 'a' && c < 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
