#include "shell_header.h"

/**
 * handle_cmnt - Handle comments in the command line by removing
 *               everything after the '#' symbol.
 * @command: the command line string
 *
 * Return: the modified command line string
 */
char *handle_cmnt(char *command)
{
	int n;

	n = 0;
	/* Look for '#' symbol in the command line */
	while (command[n])
	{
		if (command[n] == '#')
			break;
		n++;
	}

	/* Ignore the rest of the line after '#' */
	while (command[n])
	{
		command[n] = '\0';
		n++;
	}

	return (command);
}
