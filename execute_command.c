#include "shell_header.h"

/**
 * own_execve - Executes a program using the execve system call
 *
 * @args: Array of arguments for the program
 * @env: Array of environment variables
 * @exec_file: The executable file path
 *
 * Return: 1 on success, 0 on error
 */
int own_execve(char **args, char **env, char *exec_file)
{
	pid_t ret_pid;

	ret_pid = fork();
	/* Child process: Execute the program */
	if (!ret_pid)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(exec_file);
			return (0);
		}
	}
	else if (ret_pid < 0)
	{
		perror("Fork fail");
		return (0);
	}
	else
		wait(NULL);

	return (1);
}
