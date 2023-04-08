#include "hash_tables.h"
/**
*shash_table_create - creates a hash table.
*@size: size of the array of hash
*Return: a new hash table or NULL.
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->array = calloc(size, sizeof(shash_table_t));
	if (!ht->array)
		return (NULL);

	for (i = 0; i < size; i++)
		ht->array[i] =  NULL;

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}
/**
*shash_table_set - sets the key:value pair in the hash table.
*@ht: pointer to a sorted table that is to be printed
*@key: the key
*@value: the value corrsponding to the key
*Return: value corresponding to the key or NULL.
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *new_node;
	char *new_value = NULL;
	unsigned long int index;

	if (!ht || !key || !value)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	new_node = ht->shead;
	new_value = strdup(value);
	if (!new_value)
		return (0);

	while (new_node)
	{
		if (strcmp(new_node->key, key) == 0)
		{
			free(new_node->value);
			new_node->value = new_value;
			return (1);
		}
		new_node = new_node->snext;
	}

	node = malloc(sizeof(shash_node_t));
	if (!node)
	{
		free(new_value);
		return (0);
	}

	node->value = new_value;
	node->key = strdup(key);
	if (!node->key)
	{
		free(new_value);
		free(node);
		return (0);
	}
	node->next = ht->array[index];
	ht->array[index] = node;

	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		node->sprev = NULL;
		node->snext = NULL;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else
	{
		new_node = ht->shead;

		while (new_node->snext != NULL && strcmp(new_node->snext->key, key) < 0)
			new_node = new_node->snext;

		node->snext = new_node->snext;
		node->sprev = new_node;

		if (new_node->snext == NULL)
			ht->stail = node;
		else
			new_node->snext->sprev = node;

		new_node->snext = node;
	}
	return (1);
}
/**
*shash_table_get - returns a value coresponding to the key.
*@ht: pointer to a sorted table that is to be printed
*@key: the key to search for
*Return: value corresponding to the key or NULL.
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *new_node;

	if (!ht || !key || strcmp(key, "") == 0)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	if (index >= ht->size)
		return (NULL);

	new_node = ht->array[index];

	while (new_node)
	{
		if (strcmp(new_node->key, key) == 0)
			return (new_node->value);
		new_node = new_node->next;
	}
	return (NULL);
}
/**
*shash_table_print - prints a hash table using a linked list.
*@ht: pointer to a sorted table that is to be printed
*Return: None
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	node = ht->shead;

	printf("{");
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node)
			printf(", ");
	}
	printf("}\n");
}
/**
*shash_table_print_rev - prints a hash table in reverse.
*@ht: pointer to a sorted table that is to be printed
*Return: None
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	node = ht->stail;

	printf("{");
	while (node)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node)
			printf(", ");
	}
	printf("}\n");
}
/**
*shash_table_delete - deletes a hash table.
*@ht: pointer to a sorted table that is to be deleted
*Return: None
*/
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *new_node;

	node = ht->stail;
	new_node = ht->shead;

	while (node)
	{
		node = node->snext;
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		new_node = node;
	}
	free(ht->array);
	free(ht);
}
