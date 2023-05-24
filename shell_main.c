#include "shell_header.h"
#include <signal.h>

/**
 * handleSIGINT - Signal handler function for SIGINT (CTRL-C)
 *
 * @signal: interrupt integer
 *
 * Return: void
 */
void handleSIGINT(int signal)
{
	(void)signal;
	write(1, "\n$ ", 3);
}

/**
 * main - simple shell entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * @env: array of environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *command, **args;
	int n = 1;

	signal(SIGINT, handleSIGINT);
	print_err(argv[0], NULL, NULL, NULL);
	(void)argc;

	while (n)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		/* Extract command from the user input */
		command = get_cmd();
		/* Extract arguments from the user input */
		args = tokenize_args(command);

		n = exec_cmd(command, args, &env, argv[0]);
		if (command)
			free(command);
		if (args)
			free(args);
	}

	return (0);
}
