#include "shell_header.h"

/**
 * cpy_env - creates a copy of an environment variable array
 *
 * @env: the environment to copy
 *
 * Return: a copy of the environment variable array
 */
char **cpy_env(char **env)
{
	char **env_cpy;
	unsigned int n = 0, size, len;

	if (env == NULL)
		return (NULL);

	len = array_len(env);
	env_cpy = malloc(sizeof(char *) * (len + 1));
	if (!env_cpy)
		exit(1);

	while (env[n])
	{
		size = own_strlen(env[n]);
		env_cpy[n] = malloc(sizeof(char) * (size + 1));
		if (!env_cpy[n])
		{
			free_array(env_cpy);
			exit(1);
		}
		own_strcpy(env_cpy[n], env[n]);
		n++;
	}
	env_cpy[n] = NULL;
	return (env_cpy);
}
