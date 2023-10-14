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
	int status, i;
	char input[MAX_COMMAND_LENGTH];
	pid_t child_pid;
	char **commands;
	char *fullcmd;
	extern  char **environ;

	while (1)
	{
		printf("#cisfun$ ");
		fgets(input, sizeof(input), stdin);
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		commands = strtostrs(input);
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
				execve(fullcmd, commands, environ);
				perror(argv[0]);
				exit(EXIT_FAILURE);
			} else
			{
				waitpid(child_pid, &status, 0);
			}
		}
		free(fullcmd);
		for (i = 0; commands[i] != NULL; i++)
		{
			free(commands[i]);
		}
		free(commands);
	}
	return (0);
}
