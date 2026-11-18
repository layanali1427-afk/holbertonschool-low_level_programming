#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char
 * @s: Address of the pointer to change
 * @to: New value for the pointer
 *
 * Return: Nothing
 */
void set_string(char **s, char *to)
{
	*s = to;
}
