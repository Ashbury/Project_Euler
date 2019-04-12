/*
** If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
** then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
**
** If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
**
** NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters
** and 115 (one hundred and fifteen) contains 20 letters.
** The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <stdio.h>

#define TARGET 1000

static size_t	less_than_twenty_one(size_t nb)
{
	if (nb <= 0)
		return 0;
	else if (nb == 1 || nb == 2 || nb == 6 || nb == 10)
		return 3;
	else if (nb == 4 || nb == 5 || nb == 9)
		return 4;
	else if (nb == 3 || nb == 7 || nb == 8)
		return 5;
	else if (nb == 11 || nb == 12 || nb == 20)
		return 6;
	else if (nb == 15 || nb == 16)
		return 7;
	else if (nb == 17)
		return 9;
	else
		return 8;
}

static size_t	less_than_one_hundred(size_t nb)
{
	if (nb < 21)
		return less_than_twenty_one(nb);
	else if (nb < 30)
		return (6 + less_than_twenty_one(nb - 20));
	else if (nb < 40)
		return (6 + less_than_twenty_one(nb - 30));
	else if (nb < 50)
		return (5 + less_than_twenty_one(nb - 40));
	else if (nb < 60)
		return (5 + less_than_twenty_one(nb - 50));
	else if (nb < 70)
		return (5 + less_than_twenty_one(nb - 60));
	else if (nb < 80)
		return (7 + less_than_twenty_one(nb - 70));
	else if (nb < 90)
		return (6 + less_than_twenty_one(nb - 80));
	else
		return (6 + less_than_twenty_one(nb - 90));
}

static size_t	less_than_one_thousand(size_t nb)
{
	if (nb < 200)
	{
		if (nb - 100 == 0)
			return (10);
		return (13 + less_than_one_hundred(nb - 100));
	}
	else if (nb < 300)
	{
		if (nb - 200 == 0)
			return (10);
		return (13 + less_than_one_hundred(nb - 200));
	}
	else if (nb < 400)
	{
		if (nb - 300 == 0)
			return (12);
		return (15 + less_than_one_hundred(nb - 300));
	}
	else if (nb < 500)
	{
		if (nb - 400 == 0)
			return (11);
		return (14 + less_than_one_hundred(nb - 400));
	}
	else if (nb < 600)
	{
		if (nb - 500 == 0)
			return (11);
		return (14 + less_than_one_hundred(nb - 500));
	}
	else if (nb < 700)
	{
		if (nb - 600 == 0)
			return (10);
		return (13 + less_than_one_hundred(nb - 600));
	}
	else if (nb < 800)
	{
		if (nb - 700 == 0)
			return (12);
		return (15 + less_than_one_hundred(nb - 700));
	}
	else if (nb < 900)
	{
		if (nb - 800 == 0)
			return (12);
		return (15 + less_than_one_hundred(nb - 800));
	}
	else
	{
		if (nb - 900 == 0)
			return (11);
		return (14 + less_than_one_hundred(nb - 900));
	}
}

static size_t	compute_number(size_t nb)
{
	if (nb < 21)
		return less_than_twenty_one(nb);
	else if (nb < 100)
		return less_than_one_hundred(nb);
	else if (nb < 1000)
		return less_than_one_thousand(nb);
	else
		return 11;
}

int				main(void)
{
	size_t	result = 0;

	for (size_t i = 1; i <= 1000; i++)
		result += compute_number(i);

	printf("Result: %zu\n", result);
	return 0;
}