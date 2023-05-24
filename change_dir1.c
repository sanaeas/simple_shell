#include "shell_header.h"

/**
 * is_similar - Checks if the name of the variable passed by the user
 *		is similar to the name of the variable in the environment
 * @str1: the first given string
 * @str2: the second given string
 *
 * Return: 1 if the strings are similar, 0 otherwise
 */
int is_similar(char *str1, char *str2)
{
	int indx = 0;

	if (!str1 || !str2)
		return (0);

	while (str1[indx] != '\0' && str2[indx] != '\0')
	{
		if (str1[indx] != str2[indx])
			return (0);
		indx++;
	}

	if (str1[indx] == '=')
		return (1);

	return (0);
}

/**
 * find_env_var - Find an environment variable in the given environment
 *
 * @env: the environment array to search
 * @var: the variable to look for
 *
 * Return: A pointer to the environment variable if found, NULL otherwise
 */
char *find_env_var(char **env, char *var)
{
	int indx = 0;

	while (env[indx])
	{
		if (is_similar(env[indx], var))
			return (env[indx]);
		indx++;
	}
	return (NULL);
}
/**
 * get_dir_val - Extract the directory value from an environment variable
 *
 * @var_value: the var=value pair that contains the directory
 *
 * Return: extracted directory value on success, NULL on failure
 */
char *get_dir_val(char *var_value)
{
	char *dest_dir;
	int n = 0, m;

	while (var_value[n])
		n++;

	dest_dir = malloc(sizeof(char) * (n - 4));
	if (!dest_dir)
	{
		perror("Can't allocate memory for directory");
		exit(1);
	}

	n = 0;
	while (var_value[n])
	{
		if (var_value[n] == '=')
			break;
		n++;
	}
	m = 0;
	n = n + 1;
	while (var_value[n])
	{
		dest_dir[m++] = var_value[n];
		n++;
	}

	dest_dir[m] = '\0';

	return (dest_dir);
}
