#include "shell_header.h"

/**
 * track_path - Track the full path of a command.
 * @command: The command to track.
 * @env: The environment variables array.
 *
 * Return: The full path of the command, or NULL on failure.
 */
char *track_path(char *command, char **env)
{
	char *cmd, *path, **env_cpy;

	if (command == NULL || env == NULL)
	{
		perror("An error occurred while getting the full path");
		exit(1);
	}

	/* Check if the command is already a full path */
	if (command && (command[0] == '.' || command[0] == '/'))
	{
		/* Allocate memory for the command and copy it */
		cmd = malloc(sizeof(char) * (own_strlen(command) + 1));
		if (!cmd)
			return (NULL);
		own_strcpy(cmd, command);
		return (cmd);
	}
	/* Save a copy of the environment  */
	env_cpy = cpy_env(env);
	/* Get the path from the environment */
	path = find_path(env_cpy);
	/* Get the command's full path */
	cmd = cmd_path(command, path);
	free_array(env_cpy);

	return (cmd);
}

/**
 * find_path - Find the value of the PATH variable in the environment.
 * @env: The environment variables array.
 *
 * Return: The value of the PATH variable, or NULL if not found.
 */
char *find_path(char **env)
{
	char *token;
	const char *delimiter;
	int n;

	delimiter = "=";

	/* Iterate through the environment variables */
	for (n = 0; env[n]; n++)
	{
		/* Tokenize the variable using the delimiter "=" */
		token = own_strtok(env[n], delimiter);
		/* Check if the token is the "PATH" variable */
		if (!own_strcmp("PATH", token))
			break;
	}

	if (env[n])
		token = own_strtok(NULL, delimiter);
	else
		token = NULL;
	return (token);
}

/**
 * cmd_path - Find the correct path for a command within the provided path
 *
 * @command: The command to find the path for
 * @path: The search path containing directories separated by ':'
 *
 * Return: the correct path for the command
 */
char *cmd_path(char *command, char *path)
{
	const char *delimiter;
	char *token;
	char *cmd;

	if (command == NULL || path == NULL)
		exit(1);

	delimiter = ":";
	token = own_strtok(path, delimiter);
	while (token)
	{
		cmd = correct_path(token, command);
		if (cmd)
			return (cmd);
		token = own_strtok(NULL, delimiter);
	}
	return (NULL);
}
