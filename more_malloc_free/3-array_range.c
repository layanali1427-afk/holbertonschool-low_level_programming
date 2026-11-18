#include "main.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * array_range - Creates an array of integers in a range
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: Pointer to array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	size_t count, i;

	if (min > max)
		return (NULL);

	count = (size_t)((int64_t)max - (int64_t)min + 1);

	if (count > (size_t)-1 / sizeof(int))
		return (NULL);

	array = malloc(count * sizeof(int));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < count; i++)
		array[i] = (int)((int64_t)min + (int64_t)i);

	return (array);
}
