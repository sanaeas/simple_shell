#include "shell_header.h"

/**
 * setenv_var - Set an environment variable or update an existing one
 *
 * @command: The command that triggered the setenv operation
 * @args: The arguments passed to setenv
 * @env: The environment variables
 *
 * Return: Always returns 1 to indicate successful execution
 */
int setenv_var(char *command, char **args, char ***env)
{
	char **temp_env, *new_var;
	int n;

	/* Check for NULL arguments */
	if (env == NULL || command == NULL || args == NULL)
		perror("NULL argument to set env variable"), exit(1);

	/* Check for invalid argument count */
	if (!args[0] || !args[1] || !args[2] || args[3])
	{
		print_err(NULL, NULL, "Bad variable name", NULL);
		return (1);
	}

	n = already_exist(args[1], *env);
	/* If it doesn't exist, create a new var */
	if (n == -1)
	{
		temp_env = create_var(*env, args[1], args[2]);
		*env = temp_env;
	}
	else if (n >= 0)
	{
		/* Update the old variable */
		new_var = update_var(args[2], *env, n);
		free((*env)[n]);
		(*env)[n] = new_var;
	}

	return (1);
}
