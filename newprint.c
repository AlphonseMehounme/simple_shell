#include "main.h"

/**
 * env - Print the environment variables
 */
void env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
