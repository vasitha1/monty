#include "monty.h"

/**
 * check_arg - Function that correctly changes the string argument to an int
 * @argument - String to be transformed
 *
 * Return: Transformed int (success) or -1 failure
 */
int check_arg(char *argument)
{
	int i = 0;

	if (argument[0] == '-')
		i++;

	while (argument[i] != '\0')
	{
		if (!isdigit(argument[i]))
			return (-1);
		i++;
	}
	return (0);
}
