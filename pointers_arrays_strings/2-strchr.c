#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: String to search
 * @c: Character to find
 *
 * Return: Pointer to first occurrence, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);

		i++;
	}

	if (c == '\0')
		return (s + i);

	return (0);
}
