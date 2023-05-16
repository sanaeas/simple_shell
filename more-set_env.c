#include "shell_header.h"

/**
 * allocate_sp - Allocate memory for a new environment variable array
 *
 * @env: The existing environment variable array
 *
 * Return: new environment variable array on success | NULL on failure
 */
char **allocate_sp(char **env)
{
	int count, n;
	char **new_env;

	/* Count the number of existing environment variables */
	count = 0;
	while (env[count])
		count++;

	/* Allocate memory for the new array */
	new_env = (char **) malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return (NULL);

	/* Copy the existing environment variables to the new array */
	n = 0;
	while (env[n])
	{
		new_env[n] = env[n];
		env[n] = NULL;
		n++;
	}

	new_env[count] = NULL;
	new_env[count + 1] = NULL;

	return (new_env);
}
