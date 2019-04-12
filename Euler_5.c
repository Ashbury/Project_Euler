/*
** 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
** What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int main(void)
{
	unsigned int i = 2520; // Divisible by all numbers from 1 to 10.

	while (i += 20) // since 2520 is divisible by 20 and the final result has to be too.
	{
		//I tried to take the least number of numbers possible to check
		if (i % 3 == 0 && i % 5 == 0 && i % 7 == 0 && i % 11 == 0 && i % 13 == 0 
			&& i % 16 == 0 && i % 17 == 0 && i % 18 == 0 && i % 19 ==0 && i % 20 == 0)
		{
			printf("Result: %u\n", i);
			break ;
		}
	}
	return 0;
}
