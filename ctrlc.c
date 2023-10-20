#include "main.h"

/**
 * ctrlc - Ctrl C handler
 * @sig: The signal
 */
void ctrlc(int sig)
{
	if (sig == SIGINT)
	{
		print("\n ($) ", STDIN_FILENO);
	}
}
