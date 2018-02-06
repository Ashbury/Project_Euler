/*
**	If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
**	Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#include <stdlib.h>

static unsigned int     euler_1(unsigned int mult_1, unsigned int mult_2, unsigned int range)
{
    unsigned int sum = 0;

    for (unsigned int i = 0; i < range; i++)
    {
        if (i % mult_1 == 0 || i % mult_2 == 0)
            sum += i;
    }
    return sum;
}

int                     main(int ac, char **av)
{
    if (ac != 4)
    {
        fprintf(stderr, "I need three arguments: mult1, mult2, range\n");
        return -1;
    }

    unsigned int mult1 = (unsigned int)atoi(av[1]);
    unsigned int mult2 = (unsigned int)atoi(av[2]);
    unsigned int range = (unsigned int)atoi(av[3]);

    printf("The sum of all multiples of %u or %u from 0 to %u is %u\n", mult1, 
    mult2, range, euler_1(mult1, mult2, range));
    
    return 0;
}
