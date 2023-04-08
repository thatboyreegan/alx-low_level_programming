#include "hash_tables.h"
/**
*hash_table_print - printd the hash table
*@ht: pointer to the hash table
*Return: None
*/

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp_node;
	int z = 0;

	if (!ht)
		return;


	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (z == 1)
				printf(", ");

			tmp_node = ht->array[i];
			while (tmp_node)
			{
				printf("'%s': '%s'", tmp_node->key, tmp_node->value);
				tmp_node = tmp_node->next;
				if (tmp_node)
					printf(", ");
			}
			z = 1;
		}


	}
	printf("}\n");
}
