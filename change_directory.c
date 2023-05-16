#include "shell_header.h"

/**
 * change_dir - Change the current working directory
 *
 * @command: The command name (unused)
 * @args: The command arguments
 * @env: The current environment variables
 *
 * Return: 1 on success, -1 on failure
 */
int change_dir(__attribute__((unused))char *command, char **args, char ***env)
{
	char *dir, *cwd;
	char old[100];
	size_t size;

	/* Check if no arguments provided, change to HOME directory */
	if (args && args[0] && !args[1])
		dir = find_dir_val(*env, "HOME");
	/* Check if '-' argument provided, change to OLDPWD directory */
	else if (args && args[0] && !own_strcmp(args[1], "-") && !args[2])
		dir = find_dir_val(*env, "OLDPWD");
	else
		dir = copy_str(args[1]);

	size = 100;
	cwd = getcwd(old, size);
	if (!cwd)
		perror("Can't get current working directory");
	if (!dir)
		print_err(NULL, args[0], "can't cd to OLDPWD", NULL);
	else if (chdir(dir) == -1)
		print_err(NULL, args[0], "can't cd to ", dir);
	else
	{
		update_prev_dir(*env);
		update_old_pwd(*env, old);
	}

	free(dir);
	return (1);
}

/**
 * find_dir_val - Find the directory value of a specified environment variable.
 * @env: The environment variables array.
 * @var: The name of the environment variable to search for.
 *
 * Return: The directory value of the environment variable, or NULL if not found.
 */
char *find_dir_val(char **env, char *var)
{
	char *dest_dir, *var_value;

	if (!env)
		return (NULL);

	/* Find the value of the specified environment variable */
	var_value = find_env_var(env, var);

	if (!var_value)
		return (NULL);

	/* Extract the directory value from the environment variable value */
	dest_dir = get_dir_val(var_value);

	return (dest_dir);
}
