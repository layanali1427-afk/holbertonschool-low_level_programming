#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long long a = 1, b = 2, next;
	int i;

	for (i = 0; i < 50; i++)
	{
		printf("%llu", a);

		if (i < 49)
			printf(", ");

		next = a + b;
		a = b;
		b = next;
	}

	printf("\n");
	return (0);
}
