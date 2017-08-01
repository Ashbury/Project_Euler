/*
**	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
**	What is the 10 001st prime number ?
*/

#include <stdio.h>
#define TARGET 10001

static unsigned int	sqrt_tunc(unsigned int number)
{
	unsigned int i = 0;

	while (i * i < number)
		i++;
	return i;
}


//Here, I don't check if the number is even since it will already be checked by the main
static int		is_prime(unsigned int number)
{
	unsigned int i = 3;
	unsigned int square_root = sqrt_tunc(number);

	while (i <= square_root)
	{
		if (number % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

int		main(void)
{
	if (TARGET == 1)
	{
		printf("Result : 2\n");
		return 0;
	}
	
	unsigned int	i = 3;
	unsigned int	nth = 1;

	while (1)
	{
		if (is_prime(i))
		{
			nth++;
			if (nth == TARGET)
			{
				printf("Result : %u\n", i);
				break ;
			}
		}
		i += 2;
	}
	return 0;
}
