/*
** The following iterative sequence is defined for the set of positive integers:
**
** n → n/2 (n is even)
** n → 3n + 1 (n is odd)
**
** Using the rule above and starting with 13, we generate the following sequence:
**
** 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
** It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
**
** Which starting number, under one million, produces the longest chain?
**
** NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>
#include <stdlib.h>

static size_t compute_collatz(size_t nb)
{
	size_t ret = 0;
	while (nb != 1) // Okay, if the said conjecture is false, this might be an infinite loop, but I doubt it will happen will low numbers x)
	{
		if (nb % 2 == 0)
			nb /= 2;
		else
			nb = (nb * 3) + 1;
		ret++;
	}
	return ret;
}

int	 main(void)
{
	size_t highest_number = 0;
	size_t highest_chain = 0;

	for (size_t i = 1; i < 1000000; i++)
	{
		size_t chain = compute_collatz(i);
		if (chain > highest_chain)
		{
			highest_chain = chain;
			highest_number = i;
		}
	}
	printf("The under one million integer with the longest Collatz chain is %zu with a length of %zu\n", highest_number, highest_chain);
	return 0;
}
