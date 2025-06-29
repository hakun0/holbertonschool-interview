#include "slide_line.h"

/**
 * slide_line - Slides and merges an array to the left or right
 *
 * @line: Array on integers
 * @size: Size of the array
 * @direction: Direction to slide
 * Return: 1 if success, 0 otherwise
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == 2)
		return (to_left(line, size));
	if (direction == 1)
		return (to_right(line, size));
	else
		return (0);
}

/**
 * to_left - Slides and merges array elements to the left
 *
 * @line: Array on integers
 * @size: Size of the array
 * Return: 1 on success
 */

int to_left(int *line, size_t size)
{
	int cur = 0, nxt = 0;
	size_t i, index = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0 && cur == 0)
			cur = line[i];
		else if (cur != 0 && line[i] != 0)
			nxt = line[i];
		if (cur != 0 && nxt != 0)
		{
			if (cur == nxt)
			{
				line[index++] = cur + nxt;
				cur = 0;
				nxt = 0;
			}
			else
			{
				line[index++] = cur;
				cur = nxt;
				nxt = 0;
				if (i == size - 1)
					line[index++] = cur;
			}
		}
		if (cur != nxt && i == size - 1)
			line[index++] = cur;
	}
	for (i = index; i < size; i++)
		line[i] = 0;
	return (1);
}

/**
 * to_right - Slides and merges array elements to the right
 * @line: Array of integers
 * @size: Size of the array
 * Return: 1 on success
 */

int to_right(int *line, size_t size)
{
	int cur = 0, previous = 0;
	size_t i, index = size - 1;

	for (i = size - 1; i < size; i--)
	{
		if (line[i] != 0 && cur == 0)
			cur = line[i];
		else if (cur != 0 && line[i] != 0)
			previous = line[i];
		if (cur != 0 && previous != 0)
		{
			if (cur == previous)
			{
				line[index--] = cur + previous;
				cur = 0;
				previous = 0;
			}
			else
			{
				line[index--] = cur;
				cur = previous;
				previous = 0;
				if (i == 0)
					line[index--] = cur;
			}
		}
		else if (cur != previous && i == 0)
			line[index--] = cur;
	}
	for (i = 0; i < index + 1; i++)
		line[i] = 0;
	return (1);
}