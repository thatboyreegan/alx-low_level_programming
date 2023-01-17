#ifndef _DOG_H_
#define _DOG_H_
/**
 * dog_t - Typedef for struct dog.
 */
typedef struct dog_t;

/**
 * struct dog - struct that stores some information of a dog.
 * @name: name of dog.
 * @age: age of the dog.
 * @owner: owner of the dog.
 *
 * Description: struct that stores name, age and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *);

#endif
