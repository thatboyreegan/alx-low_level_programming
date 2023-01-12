#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints minimum number of coins to make change for an
 * amount of money.
 * @argc: argument count.
 * @argv: argument vector containing the amount of money at index 1.
 * Return: 0 if there are no errors.
 * 1 if the number exceeds 2.
 */
int main(int argc, char *argv[])
{
	int find_change(int amount);

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		int amount;

		amount = atoi(argv[1]);
		if (amount < 0)
			printf("0\n");
		else
			printf("%d\n", find_change(amount));

		return (0);
	}
}
/**
 * find_change - recursively divides amount to find minimum number of coins.
 * @amount: amount of money.
 * Return: number of coins.
 */
int find_change(int amount)
{
	if (amount >= 25)
		return (amount / 25 + find_change(amount % 25));
	else if (amount >= 10)
		return (amount / 10 + find_change(amount % 10));
	else if (amount >= 5)
		return (amount / 5 + find_change(amount % 5));
	else if (amount >= 2)
		return (amount / 2 + find_change(amount % 2));
	else
		return (amount);
}
