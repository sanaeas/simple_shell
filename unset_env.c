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
	if (n < 0)
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

/**
 * delete_var - deletes a variable from the environment array
 *
 * @env: the environment array
 * @indx: the index of the variable to delete
 *
 * Return: the modified environment array with the variable deleted
 */
char **delete_var(char **env, int indx)
{
	char **temp_env;
	int n = 0, m;

	if (env == NULL || indx < 0)
		return (NULL);

	while (env[n])
		n++;

	if (n <= indx)
		return (NULL);

	temp_env = malloc(sizeof(char *) * n);
	if (temp_env == NULL)
	{
		perror("Can't allocate memory for temp_env in delete var");
		exit(1);
	}
	n = 0;
	while (n < indx)
	{
		temp_env[n] = env[n], env[n] = NULL;
		n++;
	}
	free(env[n]), env[n] = NULL;

	m = n + 1;
	while (env[m])
	{
		temp_env[n++] = env[m];
		env[m] = NULL;
		m++;
	}

	temp_env[n] = NULL;
	return (temp_env);
}
