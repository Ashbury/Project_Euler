/*
** The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
** Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include <stdlib.h>

#define TARGET 2000000

/*
** The perfect limit would be the square root rounded up, but since this function will be
** called a lot and I don't need an exact result as long as it is higher, I made it faster
*/
static uint64_t	get_reasonable_limit(uint64_t number)
{
	uint64_t i = 0;

	while (i * i < number)
		i += 5;
	return i;
}

/*
** Here, I don't check if the number is even since it will already be checked by the main
*/
static int		is_prime(uint64_t number)
{
	uint64_t i = 3;
	uint64_t reasonable_limit = get_reasonable_limit(number);

	while (i <= reasonable_limit)
	{
		if (number % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

int				main(void)
{
	uint64_t ret = 2;

	for (uint64_t i = 3; i < TARGET; i += 2)
	{
		if (is_prime(i))
			ret += i;
	}
	printf("Result: %llu\n", ret);
	return 0;
}
