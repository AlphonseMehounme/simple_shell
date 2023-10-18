#include "main.h"

/**
 * freecmd - Free array of strings
 * @strar: Array of string to free
 */
void freecmd(char **strar)
{
	int i;

	for (i = 0; strar[i] != NULL; i++)
	{
		free(strar[i]);
	}
	free(strar);
}
