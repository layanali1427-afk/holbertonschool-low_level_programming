#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random valid password
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int remaining;
	int value;
	int maximum;

	remaining = 2772;
	srand((unsigned int)time(NULL));

	while (remaining > 126)
	{
		maximum = remaining - 33;

		if (maximum > 126)
			maximum = 126;

		value = 33 + rand() % (maximum - 32);
		putchar(value);
		remaining -= value;
	}

	putchar(remaining);
	putchar('\n');

	return (0);
}
