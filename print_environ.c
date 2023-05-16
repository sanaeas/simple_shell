#include "shell_header.h"

/**
 * print_env - Print the environment variables
 *
 * @command: the command name
 * @args: command arguments
 * @env: the environment to print
 *
 * Return: 1 on success
 */
int print_env(char *command, char **args, char ***env)
{
	int n = 0;

	if (command == NULL || args == NULL || env == NULL)
	{
		perror("NULL argument to print the environment");
		exit(1);
	}

	/* Write each var=value in the environment followed by new line */
	while ((*env)[n] != NULL)
	{
		write(STDOUT_FILENO, (*env)[n], own_strlen((*env)[n]));
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
	return (1);
}
