/*
**  Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
**
**  How many such routes are there through a 20×20 grid?
*/

#include <stdio.h>
#include <stdint.h>

#define TARGET (uint64_t)4

static uint64_t square(uint64_t nb)
{
    return nb * nb;
}

static uint64_t factorial(uint64_t nb)
{
    uint64_t ret = 1;
    for (uint64_t i = 2; i <= nb; i++)
    {
        ret *= i;
    }
    return ret;
}

/*
**  There is a formula to obtain the number of routes for a given square of n x n.
**  It has to do with Pascal's Triangle.
**  The formula is : (2n)! / n! ^ 2
**  The answer with 20 is too big for 64bit, so I computed it with a calculator.
*/
int     main(void)
{

    uint64_t ret = factorial(2 * TARGET) / square(factorial(TARGET));
    printf("There are %llu routes for a %llu x %llu square.\n", ret, TARGET, TARGET);
}
