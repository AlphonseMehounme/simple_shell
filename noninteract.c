#include "main.h"

/**
 * noninteract - Non interactive mode of the shell
 *
 * Return: Always 0
 */
void noninteract(char *argvo)
{
	char *input = NULL, *fullcmd, **commands;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
	while (getline(&input, &n, stdin))
	{
		commands = strtostrs(input);
		if (commands[0] != NULL)
		{
			if (strcmp(commands[0], "env") == 0 || strcmp(commands[0], "exit") == 0)
			{
				if (strcmp(commands[0], "env") == 0)
				{
					env();
					freecmd(commands);
					continue;
				}
				if (strcmp(commands[0], "exit") == 0)
				{
					freecmd(commands);
					exit(0);
				}
			}
			fullcmd = _which(commands[0]);
			ownexecve(fullcmd, commands, argvo);
			if (fullcmd != NULL && fullcmd != commands[0])
				free(fullcmd);
		}
		freecmd(commands);
		exit(0);
	}
	}
}
