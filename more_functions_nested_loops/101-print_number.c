#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @n: Integer to print
 */
void print_number(int n)
{
	unsigned int number;
	unsigned int divisor = 1;

	if (n < 0)
	{
		_putchar('-');
		number = -(unsigned int)n;
	}
	else
	{
		number = (unsigned int)n;
	}

	while (number / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		_putchar((number / divisor) + '0');
		number %= divisor;
		divisor /= 10;
	}
}
