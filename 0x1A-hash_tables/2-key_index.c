#include "hash_tables.h"
/**
*key_index - generates an index for a given key
*@key: the key
*@size: size of the associative array
*Return: an index in the array
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key);

	return (index % size);
}
