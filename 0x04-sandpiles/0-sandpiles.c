#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Prints the grid
 * @grid: grid with shape of 3
 * Return: Nada
 */

void print_grid(int grid[3][3])
{
	int trav, ultraTrav;

	printf("=\n");
	for (trav = 0; trav < 3; trav++)
	{
		for (ultraTrav = 0; ultraTrav < 3; ultraTrav++)
		{
			if (ultraTrav)
				printf(" ");
			printf("%d", grid[trav][ultraTrav]);
		}
		printf("\n");
	}
}

/**
 * sum_grids - Sum two grids
 * @grid1: sandpiles
 * @grid2: sandpiles
 * Return: Nada
 */

void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int trav, ultraTrav;

	for (trav = 0; trav < 3; trav++)
		for (ultraTrav = 0; ultraTrav < 3; ultraTrav++)
			grid1[trav][ultraTrav] = grid1[trav][ultraTrav] + grid2[trav][ultraTrav];
}

/**
 * sandpile - Check if the grid is a sandpile
 * @grid1: sandpiles stable
 * Return: 1 if false
 *          0 if true
 */

int sandpile(int grid1[3][3])
{
	int trav, ultraTrav;

	for (trav = 0; trav < 3; trav++)
		for (ultraTrav = 0; ultraTrav < 3; ultraTrav++)
			if (grid1[trav][ultraTrav] > 3)
				return (0);
	return (1);
}

/**
 * convert_sandpile - Convert the grid into a sandpile
 * @grid1: sandpiles stable
 * Return: Nada
 */

void convert_sandpile(int grid1[3][3])
{
	int trav, ultraTrav;
	int grid_aux[3][3];

	/** starting the auxiliar in 0 */
	for (trav = 0; trav < 3; trav++)
		for (ultraTrav = 0; ultraTrav < 3; ultraTrav++)
			grid_aux[trav][ultraTrav] = 0;

	for (trav = 0; trav < 3; trav++)
	{
		for (ultraTrav = 0; ultraTrav < 3; ultraTrav++)
		{
			/** verify if the number in the cell is > 3 */
			if (grid1[trav][ultraTrav] > 3)
			{
				grid1[trav][ultraTrav] -= 4;
				if ((trav - 1 >= 0) && (trav - 1 < 3))
					grid_aux[trav - 1][ultraTrav] += 1;
				if ((ultraTrav - 1 >= 0) && (ultraTrav - 1 < 3))
					grid_aux[trav][ultraTrav - 1] += 1;
				if ((trav + 1 >= 0) && (trav + 1 < 3))
					grid_aux[trav + 1][ultraTrav] += 1;
				if ((ultraTrav + 1 >= 0) && (ultraTrav + 1 < 3))
					grid_aux[trav][ultraTrav + 1] += 1;
			}
		}
	}

	sum_grids(grid1, grid_aux);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: sandpiles individually stable
 * @grid2: sandpiles individually stable
 * Return: Nada
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);

	while (!sandpile(grid1))
	{
		print_grid(grid1);
		convert_sandpile(grid1);
	}
}
