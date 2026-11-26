#include <stdio.h>

/**
 * read_number - Reads an integer and rejects invalid input
 * @value: Pointer to the integer
 *
 * Return: 1 on success, 0 on end of input
 */
int read_number(int *value)
{
	int status, c;

	while (1)
	{
		status = scanf("%d", value);

		if (status == 1)
			return (1);

		if (status == EOF)
			return (0);

		printf("Invalid number\n");

		while ((c = getchar()) != '\n' && c != EOF)
			;
	}
}

/**
 * main - Runs a calculator with four operations
 *
 * Return: 0 on success
 */
int main(void)
{
	int choice, a, b, status, c;

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

		status = scanf("%d", &choice);

		if (status == EOF)
			break;

		if (status != 1)
		{
			printf("Invalid choice\n");

			while ((c = getchar()) != '\n' && c != EOF)
				;
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

		printf("A: ");
		fflush(stdout);

		if (!read_number(&a))
			return (1);

		printf("B: ");
		fflush(stdout);

		if (!read_number(&b))
			return (1);

		if (choice == 1)
			printf("Result: %d\n", a + b);
		else if (choice == 2)
			printf("Result: %d\n", a - b);
		else if (choice == 3)
			printf("Result: %d\n", a * b);
		else if (b == 0)
			printf("Error: division by zero\n");
		else
			printf("Result: %g\n", (double)a / b);
	}

	return (0);
}
