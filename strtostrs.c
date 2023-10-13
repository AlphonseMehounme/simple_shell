#include "main.h"

/**
 * strtostrs - String to array of strings
 * @str: Input string
 *
 * Return: Array of strings
 */
char  **strtostrs(const char *str)
{
	char **strs = NULL;
	char *token;
	char copy_str[MAX_COMMAND_LENGTH];
	int i = 0;

	strs = (char **)malloc(sizeof(char *));
	if (strs == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strncpy(copy_str, str, sizeof(copy_str));
	copy_str[sizeof(copy_str) - 1] = '\0';
	token = strtok(copy_str, "\t\n");
	while (token != NULL)
	{
		strs[i] = strdup(token);
		if (strs[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		i++;
		strs = (char **)realloc(strs, (i + 1) * sizeof(char *));
		if (strs == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, "\t\n");
	}
	strs[i] = NULL;
	return (strs);
}
