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
		rm_newline(input);
		rm_comment(input);
		commands = strtostrs(input, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			currcmd = strtostrs(commands[i], " \t\n");
			if (currcmd[0] == NULL)
			{
				free(currcmd);
				break;
			}
			if (execute_builtin(currcmd, commands, input) == 1)
			{
				fullcmd = _which(currcmd[0]);
				ownexecve(fullcmd, currcmd, argvo);
				if (fullcmd != NULL && fullcmd != currcmd[0])
					free(fullcmd);
			} else
				continue;
			freecmd(currcmd);
		}
		freecmd(commands);
	}
	free(input);
	exit(status);
	}
}
