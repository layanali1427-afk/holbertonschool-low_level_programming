#include "main.h"

/**
 * rot13 - Encodes a string using ROT13
 * @str: String to encode
 *
 * Return: Pointer to the modified string
 */
char *rot13(char *str)
{
	int i;
	int j;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char encoded[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	i = 0;

	while (str[i] != '\0')
	{
		j = 0;

		while (letters[j] != '\0')
		{
			if (str[i] == letters[j])
			{
				str[i] = encoded[j];
				break;
			}

			j++;
		}

		i++;
	}

	return (str);
}
