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

/**
 * copy_str - create a copy of a string
 *
 * @str: the string to be copied
 *
 * Return: A copy of the string
 */
char *copy_str(char *str)
{
	char *str_copy;
	int n = 0;

	if (!str)
		return (NULL);

	str_copy = malloc(sizeof(char) * (own_strlen(str) + 1));
	if (!str_copy)
	{
		perror("Can't allocate memory for str copy");
		exit(1);
	}

	while (str[n])
	{
		str_copy[n] = str[n];
		n++;
	}
	str_copy[n] = '\0';
	return (str_copy);
}
