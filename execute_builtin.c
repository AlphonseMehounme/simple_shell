#include "main.h"

/**
 * execute_builtin - execute exit and env
 * @currcmd: current command
 * @commands: full command
 * @input: Input by suer
 *
 * Return: 1 or 0
 */

int execute_builtin(char **currcmd, char **commands, char *input)
{
	if (strcmp(currcmd[0], "env") == 0)
	{
		env();
		freecmd(currcmd);
		return (0);
	}
	if (strcmp(currcmd[0], "exit") == 0)
	{
		freecmd(currcmd);
		freecmd(commands);
		free(input);
		exit(2);
	}
	return (1);
}
