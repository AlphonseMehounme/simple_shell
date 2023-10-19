#include "main.h"

/**
 * ownexecve - Exec a command
 * @cmd: Command to run
 * @commands: array of strings with cmd and operator
 * @argvo: Fist argument of main
 */

void ownexecve(char *cmd, char **commands, char *argvo)
{
	pid_t child_pid;
	int status;

	if (cmd != NULL)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			execve(cmd, commands, environ);
			perror(argvo);
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}
	else
	{
		perror(argvo);
	}
}
