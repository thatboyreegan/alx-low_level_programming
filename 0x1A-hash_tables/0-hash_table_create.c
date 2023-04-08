#include "hash_tables.h"
/**
*hash_table_create - creates a new hash table.
*@size: size of the hash table
*Return: a new table or NULL if malloc failed
*/

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *ht = (hash_table_t *)malloc(sizeof(hash_table_t));

	if (!ht)
		return (NULL);

	ht->array = calloc(size, sizeof(hash_node_t));
	if (!ht->array)
		return (NULL);

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->size = size;
	return (ht);
}
