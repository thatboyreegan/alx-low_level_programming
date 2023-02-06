#include "main.h"
/**
*set_bit - set the value of a bit at a given index to 1.
*@n: pointer to an unsigned int.
*@index: index of bit to be set.
*Return: 1 if succees, -1 if failure.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	m = 1 << index;
	*n = (*n | m);

	return (1);
}
