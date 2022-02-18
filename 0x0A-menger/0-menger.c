#include "menger.h"

/**
 * calshape - Calculate the shape of the Menger Sponge
 * @row: # of Row of the Menger Sponge
 * @col: # of Col of the Menger Sponge
 * Return: 1 on success or 0 on failure
 */

int calshape(int row, int col)
{
	int shape = 0;

	if (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			return (1);
		}
		else
		{
			shape = calshape(row / 3, col / 3);
		}
		if (shape == 1)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * menger - creates a 2D array with the menger sponge
 * @level: level of the menger sponge
 * Return: 2D array
 */
void menger(int level)
{
	int i, j;
	int size = pow(3, level);

	if (level == 0)
	{
		printf("#\n");
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (calshape(i, j) == 1)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
