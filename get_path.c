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
