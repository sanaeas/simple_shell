#include "shell_header.h"

/**
 * is_built_in - Check if a command is a built-in command and return its function
 *
 * @command: The command to check
 *
 * Return: Function pointer to the built-in command if found, otherwise NULL
 */
int (*is_built_in(char *command))(char *, char **, char ***)
{
	/* Array of built-in command structs */
	bltin tuple[] = {
		{"cd", change_dir},
		{"exit", exit_program},
		{"env", print_env},
		{"setenv", setenv_var},
		{"unsetenv", unsetenv_var},
		{NULL, NULL}
	};
	int n = 0;

	/* Iterate through the array of built-in command structs */
	while (tuple[n].command)
	{
		/* Compare the command with the current built-in command */
		if (!own_strcmp(command, tuple[n].command))
			return (tuple[n].fct);
		n++;
	}
	return (NULL);
}
