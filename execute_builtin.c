#include "main.h"

/**
 * execute_builtin - execute exit and env
 * @command: command to test
 * @argvo: argvo
 *
 * Return: 1 or 0
 */

int execute_builtin(char **command, char *input)
{
	if (command[0] == NULL)
	{
		return (0);
	}
	if (strcmp(command[0], "env") == 0)
	{
		env();
		return (0);
	}
	if (strcmp(command[0], "exit") == 0)
	{
		freecmd(command);
		free(input);
		exit(2);
	}
	return (1);
}
