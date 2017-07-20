/*
**    The prime factors of 13195 are 5, 7, 13 and 29.
**    What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>
#include <stdlib.h>

#define TARGET 600851475143

// static uint32_t sqrt_up(uint64_t number)
// {
//     uint32_t    ret = 0;

//     while (ret * ret < number)
//         ret += 1;
//     return ret;
// }

static uint32_t euler_3(void)
{
    uint32_t    largest_prime_factor = 0;
    uint64_t    target = TARGET;

    if (target % 2 == 0)
    {
        largest_prime_factor = 2;
        target /= 2;
    }
    for (uint32_t i = 3; target != 1; i += 2)
    {
        if (target % i == 0)
        {
            if (i >largest_prime_factor)
                largest_prime_factor = i;
            target /= i;
            i = 3;
        }
    }
    return largest_prime_factor;
}

int             main(void)
{
    printf("Result : %u\n", euler_3());
}
