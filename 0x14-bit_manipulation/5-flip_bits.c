#include "main.h"
/**
*flip_bits - returns number of bits to be flipped to move from
*a number to another.
*@n: first number.
*@m: second number.
*Return: numbe rof bits to be flipped.
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nbits;

	for (nbits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			nbits++;
	}

	return (nbits);
}
