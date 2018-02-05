/*
**	By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
**
**	   3
**	  7 4
**	 2 4 6
**	8 5 9 3
**
**	That is, 3 + 7 + 4 + 9 = 23.
**
**	Find the maximum total from top to bottom of the triangle below:
**
**	              75
**	             95 64
**	            17 47 82
**	           18 35 87 10
**	          20 04 82 47 65
**	         19 01 23 75 03 34
**	        88 02 77 73 07 63 67
**	       99 65 04 28 06 16 70 92
**	      41 41 26 56 83 40 80 70 33
**	     41 48 72 33 47 32 37 16 94 29
**	    53 71 44 65 25 43 91 52 97 51 14
**	   70 11 33 28 77 73 17 78 39 68 17 57
**	  91 71 52 38 17 14 91 43 58 50 27 29 48
**	 63 66 04 68 89 53 67 30 73 16 69 87 40 31
**	04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ROWS 15

static int	**init_array(char *data)
{
	int		**ret;

	ret = malloc(sizeof(int*) * NB_ROWS);
	for (int i = 0; i < NB_ROWS; i++)
	{
		ret[i] = malloc(sizeof(int) * (size_t)(i + 1));
		if (i == 0)
			ret[i][0] = atoi(strtok(data, " "));
		else
			for (int j = 0; j < (i + 1); j++)
				ret[i][j] = atoi(strtok(NULL, " "));
	}

	return ret;
}

static void	place_weigth(int **array, int i)
{
	for (int j = 0; j <= i; j++)
	{
		int max = array[i + 1][j] > array[i + 1][j + 1] ? array[i + 1][j] : array[i + 1][j + 1];
		array[i][j] += max;
	}
}

static void	solve(int **array)
{
	for (int i = NB_ROWS - 2; i >= 0; i--)
		place_weigth(array, i);
	printf("Result: %d\n", array[0][0]);
}

int			main(void)
{
	char	*data = strdup("75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23");
	int		**array = init_array(data);
	
	solve(array);

	for (int i = 0; i < NB_ROWS; i++)
		free(array[i]);
	free(array);
	free(data);

	return 0;
}
