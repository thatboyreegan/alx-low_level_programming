#include "3-calc.h"
/**
 * op_add - adds two numbers.
 * @a: first number.
 * @b: second number.
 * Return: add.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two numbers.
 * @a: first number.
 * @b: second number
 * Return: difference.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_div - divides two numbers.
 * @a: first number.
 * @b: second number.
 * Return: division.
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mul - multiplies two numbers.
 * @a: first number.
 * @b: seond number.
 * Return: multiplication.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_mod - calculate modulus of two numbers.
 * @a: first number.
 * @b: second number.
 * Return: remainder of dividing the two.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
