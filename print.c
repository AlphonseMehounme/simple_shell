#include "main.h"

void print(char *str, int stream)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		write(stream, &str[i], 1);
	}
}
