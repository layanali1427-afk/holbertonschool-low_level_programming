#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a two dimensional grid of integers
 * @grid: Pointer to the grid
 * @height: Number of rows in the grid
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
