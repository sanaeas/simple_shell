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

/**
 * already_exist - Check if an environment variable already exists
 *
 * @var: The variable name to search for
 * @env: The environment variables
 *
 * Return: The index of the variable if found, -1 otherwise
 */
int already_exist(char *var, char **env)
{
	char *key;
	int n = 0;

	/* Iterate through each environment variable */
	while (env[n])
	{
		/* Find the variable name */
		key = find_var(env[n]);
		if (!key)
		{
			perror("Error while looking for the variable");
			exit(1);
		}
		/* Compare the variable name with the one we're searching for */
		if (!own_strcmp(key, var))
		{
			free(key);
			return (n);
		}
		free(key);
		n++;
	}
	return (-1);
}

/**
 * find_var - Find the variable name in an environment variable string
 *
 * @env_var: The environment variable string in the format "key=value"
 *
 * Return: The variable name if found, NULL otherwise
 */
char *find_var(char *env_var)
{
	char *key;
	int n = 0, m = 0;

	/* Check for NULL argument */
	if (env_var == NULL)
	{
		perror("NULL argument to find variable");
		exit(1);
	}
	/* Find the position of the equal sign '=' */
	while (env_var[n] && env_var[n] != '=')
		n++;

	/* If no equal sign is found, return NULL */
	if (!env_var[n])
		return (NULL);

	key = malloc(sizeof(char) * (n + 1));
	/* Copy the variable name from the environment variable */
	while (env_var[m] && env_var[m] != '=')
	{
		key[m] = env_var[m];
		m++;
	}
	key[m] = '\0';

	return (key);
}

