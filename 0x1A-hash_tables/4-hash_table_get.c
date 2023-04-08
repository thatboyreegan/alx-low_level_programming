#include "hash_tables.h"
/**
*hash_table_get - returns a value corresponding to the key
*@ht: pointer to the hash table
*@key: key to search for
*Return: the value associated with the key or NULL
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (!ht || !ht->array || !key || strcmp(key, "") == 0)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];
	if (!node)
		return (NULL);
	if (strcmp(node->key, key) == 0)
		return (node->value);
	else
		return (NULL);
}
