#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * menger - Drwas a 2D Menger Sponge.
 * @level: level of the menger sponge to draw.
 * Return: Nothing.
 */

void menger(int level)
{
	int i, k, size, l, m;
	char hashtag;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (k = 0; k < size; k++)
		{
			l = i;
			m = k;
			hashtag = '#';

			while (l > 0)
			{
				if (l % 3 == 1 && m % 3 == 1)
				{
					hashtag = ' ';
				}
				l /= 3;
				m /= 3;
			}
			printf("%c", hashtag);
		}
		printf("\n");
	}
}
