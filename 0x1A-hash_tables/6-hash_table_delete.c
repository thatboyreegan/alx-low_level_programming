#include "hash_tables.h"
/**
*hash_table_delete - deletes the hash table
*@ht: pointer to the hash table
*Return: None
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			ht->array[i] = ht->array[i]->next;
			free(node->key);
			free(node->value);
			free(node);
			node = ht->array[i];

		}
	}
	free(ht->array);
	free(ht);
}
