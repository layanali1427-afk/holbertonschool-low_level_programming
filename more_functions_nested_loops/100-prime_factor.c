#include <stdio.h>

/**
 * main - Finds the largest prime factor of a number
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long number = 612852475143UL;
	unsigned long factor = 2;
	unsigned long largest = 0;

	while (factor <= number / factor)
	{
		if (number % factor == 0)
		{
			largest = factor;
			number /= factor;
		}
		else
		{
			factor++;
		}
	}

	if (number > largest)
		largest = number;

	printf("%lu\n", largest);
	return (0);
}
