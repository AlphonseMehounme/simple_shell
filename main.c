#include "main.h"

/**
 * main - A simple shell
 * @ac: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int __attribute__((unused)) ac, char *argv[])
{
	char *input = NULL, *fullcmd, **commands, **currcmd;
	size_t n;
	int status = 0, i;

	signal(SIGINT, ctrlc);
	while (1)
	{
		noninteract(argv[0]);
		print(" ($) ", STDOUT_FILENO);
		if (getline(&input, &n, stdin) == -1)
		{
			free(input);
			exit(status);
		}
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
			if (strcmp(currcmd[0], "env") == 0)
			{
				env();
				freecmd(currcmd);
				continue;
			}
			if (strcmp(currcmd[0], "exit") == 0)
			{
				freecmd(currcmd);
				freecmd(commands);
				free(input);
				exit(2);
			}
			fullcmd = _which(currcmd[0]);
			ownexecve(fullcmd, currcmd, argv[0]);
			if (fullcmd != NULL && fullcmd != currcmd[0])
				free(fullcmd);
			freecmd(currcmd);
		}
		freecmd(commands);
	}
	free(input);
	return (status);
}
