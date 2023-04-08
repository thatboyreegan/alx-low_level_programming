#include "hash_tables.h"
/**
*hash_table_set - adds a new element to the hash table
*@ht: pointer to the hash table to add to
*@key: the key of the new element.
*@value: value corresponding to key
*Return: 1 if successful 0 if otherwise
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
   hash_node_t *current_item;
   unsigned long int index, n;
   char *new_value;

	if (strcmp(key, "") == 0 || !key || !ht || !ht->array)
			return (0);

   new_value = strdup(value);
   if (!new_value)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	for (n = index; ht->array[n]; n++)
	{
			if (strcmp(ht->array[n]->key, key) == 0)
			{
				free(ht->array[n]->value);
				ht->array[n]->value = new_value;
				return (1);
			}
	}

   current_item = (hash_node_t *)malloc(sizeof(hash_node_t));
   if (!current_item)
   {
		free(new_value);
		return (0);
   }
   current_item->key = strdup(key);
   if (!current_item->key)
   {
		free(current_item);
		return (0);
   }
   current_item->value = new_value;

   current_item->next = ht->array[index];
   ht->array[index] = current_item;

   return (1);
}
