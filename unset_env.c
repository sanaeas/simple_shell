#include "shell_header.h"

/**
 * unsetenv_var - unset an environment variable
 *
 * @command: the command triggering the unset operation
 * @args: arguments passed to the command
 * @env: the environment array
 *
 * Return: 1 on success
 */
int unsetenv_var(char *command, char **args, char ***env)
{
	int n;
	char **temp_env;

	if (command == NULL || env == NULL || args == NULL)
	{
		perror("NULL argument to unset environment function");
		exit(1);
	}

	if (args[0] == NULL || args[1] == NULL || args[2] != NULL)
	{
		print_err(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}

	n = already_exist(args[1], *env);
	if (n == -1)
	{
		print_err(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}
	temp_env = delete_var(*env, n);
	free(*env);
	*env = NULL;
	*env = temp_env;

	return (1);
}
