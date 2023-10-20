#include "main.h"

/**
 * print - Prints strings
 * @str: String to print
 * @stream: Stream to print into
 */
void print(char *str, int stream)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		write(stream, &str[i], 1);
	}
}
