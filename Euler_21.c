/*
**	Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
**	If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
**
**	For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
**
**	Evaluate the sum of all the amicable numbers under 10000.
*/

#include <stdio.h>

#define TARGET 10000

static size_t	sum_of_divisors(size_t nb)
{
	size_t	ret = 0;

	for(size_t i = 1; i < nb; i++)
	{
		if (nb % i == 0)
			ret += i;
	}
	return ret;
}

int	main(void)
{
	size_t	result = 0;

	for(size_t i = 220; i < TARGET; i++)
	{
		size_t sum = sum_of_divisors(i);
		if (sum != i && sum_of_divisors(sum) == i)
			result += i;
	}
	printf("Result: %zu\n", result);
	return 0;
}
