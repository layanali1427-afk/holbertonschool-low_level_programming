#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long a_high = 0, a_low = 1;
	unsigned long b_high = 0, b_low = 2;
	unsigned long next_high, next_low;
	int i;

	for (i = 1; i <= 98; i++)
	{
		if (a_high == 0)
			printf("%lu", a_low);
		else
			printf("%lu%09lu", a_high, a_low);

		if (i < 98)
			printf(", ");

		next_low = a_low + b_low;
		next_high = a_high + b_high;

		if (next_low >= 1000000000UL)
		{
			next_low -= 1000000000UL;
			next_high++;
		}

		a_high = b_high;
		a_low = b_low;
		b_high = next_high;
		b_low = next_low;
	}

	printf("\n");
	return (0);
}
