#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all program arguments
 * @ac: Number of arguments
 * @av: Array of argument strings
 *
 * Return: Pointer to new string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, length;

	if (ac <= 0 || av == NULL)
		return (NULL);

	length = 0;
	for (i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);
		for (j = 0; av[i][j] != '\0'; j++)
			length++;
		length++;
	}

	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			str[k++] = av[i][j];
		str[k++] = '\n';
	}
	str[k] = '\0';

	return (str);
}
