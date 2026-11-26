#include <stdio.h>

/**
 * main - Displays calculator menu and validates choices
 *
 * Return: Always 0
 */
int main(void)
{
	int choice;
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
			printf("Invalid choice\n");
	}

	return (0);
}
