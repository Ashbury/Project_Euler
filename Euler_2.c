/*
** Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
** 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
** By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include <stdio.h>
#include <stdlib.h>

#define FIB_LIMIT 4000000

static uint64_t euler_2(void)
{
    uint64_t  sum = 0;
    uint64_t  previous = 1;
    uint64_t  ante_previous = 0;

    while (1)
    {
        uint64_t actual = previous + ante_previous;
        if (actual > FIB_LIMIT)
            break ;
        if (actual % 2 == 0)
            sum += actual;
        ante_previous = previous;
        previous = actual;
    }
    return sum;
}

int     main(void)
{
    printf("Result: %llu\n", euler_2());

    return 0;
}
