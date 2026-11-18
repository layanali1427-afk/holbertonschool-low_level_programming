#include "main.h"
#include <stdlib.h>

/**
 * error_exit - Prints Error and exits with status 98
 */
void error_exit(void)
{
	char *msg = "Error\n";
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		_putchar(msg[i]);
	exit(98);
}

/**
 * str_length - Gets the length of a string
 * @s: String to measure
 *
 * Return: Length of the string
 */
int str_length(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * valid_number - Checks whether a string contains only digits
 * @s: String to check
 *
 * Return: 1 if valid, otherwise 0
 */
int valid_number(char *s)
{
	int i;

	if (s[0] == '\0')
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * multiply - Multiplies two numbers represented as strings
 * @a: First number
 * @b: Second number
 * @result: Array to store the product
 * @n: Length of the first number
 * @m: Length of the second number
 */
void multiply(char *a, char *b, int *result, int n, int m)
{
	int i, j, sum;

	for (i = n - 1; i >= 0; i--)
	{
		for (j = m - 1; j >= 0; j--)
		{
			sum = (a[i] - '0') * (b[j] - '0');
			sum += result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
}

/**
 * main - Multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int n, m, i, start;
	int *result;

	if (argc != 3)
		error_exit();
	if (!valid_number(argv[1]) || !valid_number(argv[2]))
		error_exit();

	n = str_length(argv[1]);
	m = str_length(argv[2]);
	result = malloc(sizeof(int) * (n + m));
	if (result == NULL)
		error_exit();

	for (i = 0; i < n + m; i++)
		result[i] = 0;

	multiply(argv[1], argv[2], result, n, m);

	start = 0;
	while (start < n + m - 1 && result[start] == 0)
		start++;

	for (i = start; i < n + m; i++)
		_putchar(result[i] + '0');
	_putchar('\n');

	free(result);
	return (0);
}
