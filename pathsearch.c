#include "main.h"
#include <sys/stat.h>

/**
 * _which - Search for a program in the path
 * @str: Program to search for
 *
 * Return: Abolute path to the program
 */
char *_which(char *str)
{
	char *tok;
	char *newstr;
	char copy_str[100];
	struct stat st;

	if (str != NULL)
	{
		if (stat(str, &st) == 0)
		{
			return (str);
		}
		newstr = (char *)malloc(sizeof(char) * 50);
		strcpy(copy_str, getenv("PATH"));
		tok = strtok(copy_str, ":");
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
