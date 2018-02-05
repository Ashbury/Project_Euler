/*
**	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
**	a^2 + b^2 = c^2
**	For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
**
**	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
**	Find the product abc.
*/

#include <stdio.h>
#include <stdlib.h>

#define TARGET 1000

/*
**	Here, I don't check if a < b < c, because the main will do it.
*/
static int	is_a_pythagorean_triplet(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a * a + b * b) == c * c); // I allow this one-liner since it is simple enough.
}

/*
** I've implemented it to find all combinations if more than one exists.
*/
int		main(void)
{
	uint32_t	a = 1;
	uint32_t	b = 2;
	uint32_t	c = TARGET - a - b;
	uint8_t		found = 0;

	while (1)
	{
		if (is_a_pythagorean_triplet(a, b, c))
		{
			printf("Result: %u with a = %u, b = %u, c = %u\n", a * b * c, a, b, c);
			found++;
		}
		b++;
		c--;
		if (b > c)
		{
			a++;
			b = a + 1;
			c = TARGET - a - b;
			if (b > c)
			{
				if (found == 0)
					printf("There are no Pythagorean triples for which a + b + c = %d\n", TARGET);
				break ;
			}
		}
	}
	return 0;
}
