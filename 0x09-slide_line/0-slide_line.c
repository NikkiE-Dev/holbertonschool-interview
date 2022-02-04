#include "slide_line.h"

/**
 * slide_left - Slides an array to the left
 * @line: Pointer to the array of integer to be slid
 * @size: Number of elements in line
 */
void slide_left(int *line, size_t size)
{
size_t i, j = 0;
int tmp;

	for (i = 0; i < size && j < size; i++)
	{
		while (line[j] != 0)
			j++;

		if (line[i] != 0 && i > j)
		{
			tmp = line[i];
			line[i] = line[j];
			line[j] = tmp;
		}
	}
}

/**
 * slide_right - Slides an array to the right
 * @line: Pointer to the array of integer to be slid
 * @size: Number of elements in line
 */
void slide_right(int *line, size_t size)
{
	int i, j = size - 1;
	int tmp;

	for (i = size - 1; i >= 0 && j >= 0; i--)
	{
		while (line[j] != 0 && j > 0)
			j--;

		if (line[i] != 0 && i < j)
		{
			tmp = line[i];
			line[i] = line[j];
			line[j] = tmp;
		}
	}
}
/**
 * slide_line - Slides a line of integers to the left or right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in line
 * @direction: Direction to slide the line
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, tmp;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 1; i <= size && line[i] != 0; i++)
		{
			if (line[i] == line[i - 1])
			{
				line[i - 1] *= 2;
				line[i] = 0;
				tmp = 1;
			}
		}
		if (tmp)
		slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1; i > 0 && line[i - 1] != 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
				tmp = 1;
			}
		}
		if (tmp)
			slide_right(line, size);
	}
	else
		return (0);

	return (1);
}
