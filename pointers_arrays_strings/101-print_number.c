#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @n: Integer to print
 */
void print_number(int n)
{
	unsigned int number;
	unsigned int divisor;

	if (n < 0)
	{
		_putchar('-');
		number = 0u - (unsigned int)n;
	}
	else
	{
		number = (unsigned int)n;
	}

	divisor = 1;

	while (number / divisor >= 10)
		divisor *= 10;

	while (divisor > 0)
	{
		_putchar('0' + number / divisor);
		number %= divisor;
		divisor /= 10;
	}
}
