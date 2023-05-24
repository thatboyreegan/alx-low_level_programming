#!/usr/bin/python3
"""Module containing island_perimeter(grid)"""


def island_perimeter(grid):
    """returns the perimeter of an island

    Args:
        grid (list of lists): description of the island
    """
    perimter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4

                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

        return perimeter
