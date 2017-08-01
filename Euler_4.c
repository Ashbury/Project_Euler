/*
**	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
**	Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

static void strrev(char *str)
{
    size_t  i = 0;
	size_t	len = strlen(str);
	char	tmp;

	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

static int		is_palindromic(unsigned int nb)
{
	char	str[7] = {0}; //7 since the largest number possible is 999 * 999 = 998001	
	char	rev[7] = {0};

	sprintf(str, "%u", nb);
	sprintf(rev, "%u", nb);
	strrev(rev);
	if (strcmp(str, rev))
		return 0;
	else
		return 1;
}

int		main()
{
	unsigned int i = 999;
	unsigned int j = 999;
	unsigned int res = 0;
	while (j > 900)
	{
		unsigned int nbr = i * j;
		if (nbr > res && is_palindromic(nbr))
		{
			res = nbr;
			i = 1;
		}
		i--;
		if (i == 0)
		{
			j--;
			i = j;
		}
	}
	printf("Result : %d\n", res);
	return 0;
}
