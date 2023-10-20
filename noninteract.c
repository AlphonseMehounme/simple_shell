#include "main.h"

/**
 * noninteract - Non interactive mode of the shell
 * @argvo: First argument of main
 *
 */
void noninteract(char *argvo)
{
	char *input = NULL, *fullcmd, **commands, **currcmd;
	size_t n = 0;
	int i, status = 0;

	if (!(isatty(STDIN_FILENO)))
	{
	while (getline(&input, &n, stdin) != -1)
	{
		commands = strtostrs(input, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			currcmd = strtostrs(commands[i], " \t\n");
			if (currcmd[0] == NULL)
			{
				free(currcmd);
				break;
			}
			if (strcmp(currcmd[0], "env") == 0)
			{
				env();
				freecmd(currcmd);
				continue;
			}
			if (strcmp(currcmd[0], "exit") == 0)
			{
				freecmd(currcmd);
				exit(2);
			}
			fullcmd = _which(currcmd[0]);
			ownexecve(fullcmd, currcmd, argvo);
			if (fullcmd != NULL && fullcmd != commands[0])
				free(fullcmd);
		}
		freecmd(commands);
	}
	free(input);
	exit(status);
	}
}
