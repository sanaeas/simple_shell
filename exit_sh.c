#include "shell_header.h"

/**
 * exit_program - Exit the shell program
 *
 * @command: The command that triggered the exit
 * @args: The arguments passed to the exit command
 * @env: The environment variables
 *
 * Return: Always returns 1 to indicate successful execution
 */
int exit_program(char *command, char **args, char ***env)
{
	int n;

	/* Check for NULL arguments */
	if (command == NULL || args == NULL || env == NULL)
	{
		perror("NULL argument to exit");
		exit(1);
	}

	/* Check if an exit status is provided */
	if (args[1] == NULL)
	{
		n = 0;
	}
	else
	{
		n = own_atoi(args[1]);
		/* Check for an invalid exit status */
		if (n == 0 && own_strcmp(args[1], "0") != 0)
		{
			print_err(NULL, command, "Illegal number", args[1]);
			return (1);
		}
	}

	free(command);
	free(args);
	exit(n);
	return (1);
}
