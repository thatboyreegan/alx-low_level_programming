#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * free_grid - use free function on previous grid.
 * @grid: 2 dimensional array to free.
 * @height: input height.
 * Return: freed grid.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid != NULL || height != 0)
	{
		for (i = 0; i < height; i++)
		{
			free(grid[i]);
		}
		free(grid);
	}
}
