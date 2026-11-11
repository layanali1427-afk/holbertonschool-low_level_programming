#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: String to convert
 *
 * Return: Converted integer, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int i;
	int negative;
	unsigned int number;

	i = 0;
	negative = 0;
	number = 0;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			negative = !negative;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10u + (unsigned int)(s[i] - '0');
		i++;
	}

	if (negative)
		return ((int)(0u - number));

	return ((int)number);
}
