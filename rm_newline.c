#include "main.h"

/**
 * rm_newline - remove newline
 * @input: string to remove comment
 * Return: Nothing
 */

void rm_newline(char *input)
{
	int i = 0;

	while (input[i] != '\0')
	{
		if (input[i] == '\n')
			break;
		i++;
	}
	input[i] = '\0';
}



/**
 * rm_comment - remove comment
 * @input: sring to remove comment
 * Return: Nothing
 */

void rm_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] ==  ' ')
			break;
		i++;
	}
	input[i] = '\0';
}
