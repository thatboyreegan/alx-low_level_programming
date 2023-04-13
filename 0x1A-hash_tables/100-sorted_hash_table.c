#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct shash_node_s - Node of a sorted hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 * @sprev: A pointer to the previous element of the sorted linked list
 * @snext: A pointer to the next element of the sorted linked list
 */
typedef struct shash_node_s
{
     char *key;
     char *value;
     struct shash_node_s *next;
     struct shash_node_s *sprev;
     struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 * @stail: A pointer to the first element of the sorted linked list
 * @stail: A pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
     unsigned long int size;
     shash_node_t **array;
     shash_node_t *shead;
     shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}


unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key);

	return (index % size);
}


shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->array = calloc(size, sizeof(shash_node_t *));
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
    {
        ht->array[i] = NULL;
    }

    ht->shead = NULL;
    ht->stail = NULL;
    ht->size = size;

    return (ht);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *lhead, *node;
    unsigned long int index;
    char *new_value;

    if (!ht || !key || !value)
        return (0);

    index = key_index((unsigned char *)key, ht->size);

    lhead = ht->shead;
    new_value = strdup(value);
    if (!new_value)
        return (0);
    while (lhead)
    {
        if (strcmp(lhead->key, key) == 0)
        {
            free(lhead->value);
            lhead->value = new_value;
            return (1);
        }
        lhead = lhead->snext;
    }

    node = malloc(sizeof(shash_node_t));
    if (!node)
    {
        free(new_value);
        return (0);
    }
    
    node->key = strdup(key);
    if (!node->key)
    {
        free(new_value);
        free(node);
        return (0);
    }
    node->value = new_value;
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
        node->snext = ht->shead;
        ht->shead->sprev = node;
        ht->shead = node;
    }
    else
    {
        lhead = ht->shead;

        while (lhead->snext != NULL && strcmp(lhead->snext->key, key) < 0)
            lhead = lhead->snext;
        node->sprev = lhead;
        node->snext = lhead->snext;

        if (!lhead->snext)
            ht->stail =  node;
        else
            lhead->snext->sprev = node;
        lhead->snext = node;
    }

    return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *node;
    char *new_key;

    if (!ht || !key)
        return (NULL);
    
    new_key = strdup(key);
    if (!new_key)
    {
        free(new_key);
        return (NULL);
    }

    index = key_index((unsigned char *)new_key, ht->size);
    if (index >= ht->size)
        return (NULL);

    node = ht->array[index];

    while (node)
    {
        if (strcmp(node->key, new_key) == 0)
            return (node->value);
        node = node->next;
    }
    return (NULL);
}

void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *tmp;

    if (!ht)
        return;
    
    tmp = ht->shead;
    printf("{");
    while (tmp)
    {
        printf("'%s': '%s'", tmp->key, tmp->value);
        tmp = tmp->snext;
        if (tmp != NULL)
            printf(", ");
    }
    printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *tmp;

    if (ht)
        return;
    
    tmp = ht->stail;

    printf("{");
    while (tmp)
    {
        printf("'%s': '%s'", tmp->key, tmp->value);
        tmp = tmp->sprev;
        if (tmp != NULL)
            printf(", ");
    }
    printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *new_node;
    shash_table_t *tmp = ht;

    if (!ht)
        return;

    node =  ht->shead;
    while (node)
    {
        
        new_node = node->snext;
        free(node->key); 
        free(node->value); 
        free(node);
        node = new_node; 
    }
    free(tmp->array);
    free(tmp);
}

int main(void)
{
    shash_table_t *ht;

    ht = shash_table_create(1024);
    shash_table_set(ht, "y", "0");
    shash_table_print(ht);
    shash_table_set(ht, "j", "1");
    shash_table_print(ht);
    shash_table_set(ht, "c", "2");
    shash_table_print(ht);
    shash_table_set(ht, "b", "3");
    shash_table_print(ht);
    shash_table_set(ht, "z", "4");
    shash_table_print(ht);
    shash_table_set(ht, "n", "5");
    shash_table_print(ht);
    shash_table_set(ht, "a", "6");
    shash_table_print(ht);
    shash_table_set(ht, "m", "7");
    shash_table_print(ht);
    shash_table_print_rev(ht);
        shash_table_delete(ht);
    return (EXIT_SUCCESS);
}