#include "slide_line.h"
#include <stdio.h>

/**
 * slide_left - Slide to the left.
 * @line: Points to an array
 * @size: Number of elements.
 * Return:
 *  1 upon success or 0 upon failure
 */

void slide_left(int *line, size_t size)
{
	size_t trav = 0, rec = 0, tmp;

	for (trav = 0, rec = 0; trav < size;)
	{
		if (line[trav] == 0)
			while (line[trav] == 0)
				trav++;

		if (trav == (size - 1))
			break;

		rec = trav + 1;

		if (line[rec] == 0)
		{
			while (line[rec] == 0)
				rec++;
		}
		if (line[trav] == line[rec])
		{
			line[trav] = line[trav] + line[rec];
			line[rec] = 0;
			trav = rec + 1;
		} else
		{
			trav++;
		}
		rec = 0;
	}
	for (trav = 0, tmp = 0; trav < size; trav++)
	{
		if (line[trav] != 0)
			line[tmp++] = line[trav];
	}
	while (tmp < size)
		line[tmp++] = 0;
}

/**
 * slide_right - Slide to the right.
 * @line: Points to an array
 * @size: Number of elements.
 * Return:
 *  1 upon success or 0 upon failure
 */

void slide_right(int *line, size_t size)
{
	size_t trav, rec;

	for (trav = size; trav > 0; trav--)
	{
		for (rec = trav - 1; rec > 0; rec--)
		{
			if (line[trav - 1] != 0)
			{
				if (line[trav - 1] == line[rec - 1])
				{
					line[trav - 1] = line[trav - 1] + line[rec - 1];
					line[rec - 1] = 0;
					break;
				}
				if (line[trav - 1] != line[rec - 1] && line[rec - 1] != 0)
				{
					break;
				}
			}
			if (line[trav - 1] == 0)
			{
				if (line[rec - 1] != 0)
				{
					line[trav - 1] = line[rec - 1];
					line[rec - 1] = 0;
					trav++;
					break;
				}
			}
		}
	}
}

/**
 * slide_line - 2048 game.
 * @line: Points to an array
 * @size: Number of elements.
 * @direction: Direction can be left or rigth.
 * Return:
 *  1 upon success or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		return (0);
	}
	if (line == NULL || size == 0)
	{
		return (0);
	}
	if (direction == 0)
	{
		slide_left(line, size);
	}
	if (direction == 1)
	{
		slide_right(line, size);
	}
	return (1);
}
