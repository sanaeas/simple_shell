#include "shell_header.h"

/**
 * get_cmd - Reads a line from stdin and returns it as a string
 * Return: The command line entered by the user
 */
char *get_cmd()
{
	char *buf = NULL; /* buffer to store command line */
	size_t n = 0;

	/* Read line from stdin stream */
	if (getline(&buf, &n, stdin) == -1)
	{
		/* No input: Add new line, and exit */
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		free(buf);
		buf = NULL;
		exit(0);
	}

	handle_cmnt(buf);
	if (buf && (buf[0] == '\0'))
		buf[0] = '\n';

	return (buf);
}

char **tokenize_args(char *buf)
{
	int n = 0;
	const char *delimiter;
	char **args;
	char *token;

	args = malloc(sizeof(char *) * (1000));
	if (!args)
		exit(1);

	delimiter = " \t\n\r";
	/* Extracted token from buffer */
	token = own_strtok(buf, delimiter);

	while (token != NULL)
	{
		args[n++] = token;
		token = own_strtok(0, delimiter);
	}
	while (n < 1000)
			args[n++] = NULL;

	return (args);
}

int exec_cmd(char *command, char **args, char ***env, char *exec_file)
{
	char *cmd;
	char *temp;
	int n;
	int (*fct)(char *, char **, char ***);

	if (!command || !args || !env || !exec_file)
	{
		perror("An error occurred while executing the command");
		return (0);
	}
	if (args && !args[0])
		return (1);

	/* Check if the command is a built-in command */
	fct = is_built_in(args[0]);
	if (fct)
		return (fct(command, args, env));

	temp = args[0];
	cmd = track_path(args[0], *env);
	if (!cmd)
	{
		print_err(NULL, args[0], "not found", NULL);
		n = 1;
	}
	else
	{
		args[0] = cmd;
		n = own_execve(args, *env, exec_file);
		free(cmd);
		args[0] = temp;
	}
	return (n);
}
