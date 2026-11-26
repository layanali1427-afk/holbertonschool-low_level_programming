#include <stdio.h>

/**
 * main - Runs a calculator with addition, subtraction and multiplication
 *
 * Return: 0 on success
 */
int main(void)
{
	int choice, a, b;
	int result;

	printf("Simple Calculator\n");

	while (1)
	{
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");
		fflush(stdout);

		result = scanf("%d", &choice);

		if (result != 1)
		{
			if (result == EOF)
				break;

			printf("Invalid choice\n");
			scanf("%*s");
			continue;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice < 1 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		if (choice >= 1 && choice <= 3)
		{
			printf("A: ");
			fflush(stdout);

			if (scanf("%d", &a) != 1)
				return (1);

			printf("B: ");
			fflush(stdout);

			if (scanf("%d", &b) != 1)
				return (1);

			if (choice == 1)
				printf("Result: %d\n", a + b);
			else if (choice == 2)
				printf("Result: %d\n", a - b);
			else
				printf("Result: %d\n", a * b);
		}
	}

	return (0);
}
