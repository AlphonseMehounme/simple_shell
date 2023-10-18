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
	int status;
	char input[MAX_COMMAND_LENGTH], *fullcmd, **commands;
	pid_t child_pid;

	while (1)
	{	printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
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
			if (fullcmd != NULL)
			{
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				if (child_pid == 0)
				{
					execve(fullcmd, commands, NULL);
					perror(argv[0]);
					exit(EXIT_FAILURE);
				} else
					waitpid(child_pid, &status, 0);
			} else
				perror(argv[0]);
		}
		freecmd(commands);
	}
	return (0);
}
