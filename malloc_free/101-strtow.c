#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts words in a string
 * @str: String to check
 *
 * Return: Number of words
 */
static int count_words(char *str)
{
	int i, count;

	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}
	return (count);
}

/**
 * free_words - Frees allocated words
 * @words: Array of words
 * @count: Number of allocated words
 *
 * Return: Nothing
 */
static void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
}

/**
 * strtow - Splits a string into words
 * @str: String to split
 *
 * Return: Array of words, or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);
	count = count_words(str);
	if (count == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		len = 0;
		while (str[i + len] != '\0' && str[i + len] != ' ')
			len++;
		words[k] = malloc(sizeof(char) * (len + 1));
		if (words[k] == NULL)
		{
			free_words(words, k);
			return (NULL);
		}
		for (j = 0; j < len; j++)
			words[k][j] = str[i + j];
		words[k][len] = '\0';
		k++;
		i += len;
	}
	words[k] = NULL;
	return (words);
}
