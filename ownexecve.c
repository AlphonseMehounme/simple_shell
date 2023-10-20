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
			if (execve(cmd, commands, environ) == -1)
			{
				perror(getenv("PWD"));
				exit(2);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
			status >>= 8;
		}
	}
	else
	{
		print(argvo, STDERR_FILENO);
		print(": 1: ", STDERR_FILENO);
		print(commands[0], STDERR_FILENO);
		print(": not found\n", STDERR_FILENO);
		status = 127;
	}
}
