#include "sandpiles.h"

/**
 * sandpiles_sum - adds two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int temp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	while (is_grid_stable(grid1) == 0)
	{
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
		   for (j = 0; j < 3; j++)
		   {
			   temp[i][j] = 0;
		   }
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j != 0 && grid1[i][j - 1] > 3)
					temp[i][j]++;
				if (j != 2 && grid1[i][j + 1] > 3)
					temp[i][j]++;
				if (i != 0 && grid1[i - 1][j] > 3)
					temp[i][j]++;
				if (i != 2 && grid1[i + 1][j] > 3)
					temp[i][j]++;
			}
		 }
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
					grid1[i][j] = grid1[i][j] - 4;
				grid1[i][j] = grid1[i][j] + temp[i][j];
			}
		}
	}
}
/**
 * is_grid_stable - checks if the grid is stable
 * @grid: grid to check
 * Return: 1 if stable, 0 if not
 */
int is_grid_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
