#include "main.h"
#include <sys/stat.h>

/**
 * pathsearch - Search for a program in the path
 * @str: Program to search for
 *
 * Return: Abolute path to the program
 */
char *_which(char *str)
{
	char *tok;
	char *newstr;
	struct stat st;

	if (str != NULL)
	{
		if (stat(str, &st) == 0)
		{
			return (str);
		}
		newstr = (char *)malloc(sizeof(char) * 50);
		tok = strtok(getenv("PATH"), ":");
		while (tok != NULL)
		{
			strcpy(newstr, tok);
			strcat(newstr, "/");
			strcat(newstr, str);
			if (stat(newstr, &st) == 0)
			{
				return (newstr);
			}
			tok = strtok(NULL, ":");
		}
	}
	return (NULL);
}
