#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints integers separated by a string
 * @separator: String printed between integers
 * @n: Number of integers to print
 *
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	va_end(args);
	printf("\n");
}
