#include "shell_header.h"

/**
 * print_err - print an error message to the standard error output
 *
 * @exec_file: the name of the executable file
 * @cmd: command associated with the error
 * @error: the error message
 * @text: additional text or information related to the error
 *
 * Return: void
 */
void print_err(char *exec_file, char *cmd, char *error, char *text)
{
	char *err_msg;
	static char *exec;
	static unsigned int n;
	unsigned int indx;

	if (exec_file)
	{
		exec = exec_file;
		return;
	}

	if (!n)
		++n;
	err_msg = malloc(sizeof(char) * 100);
	if (!err_msg)
	{
		perror("Can't allocate memory for error message");
		exit(1);
	}

	indx = print_exec_prog(err_msg, exec, n);
	n++;
	indx = add_command(err_msg, cmd, indx);
	indx = add_error_msg(err_msg, error, indx);
	indx = add_more_text(err_msg, text, error[0], indx);

	err_msg[indx++] = '\n';
	err_msg[indx] = '\0';
	write(STDERR_FILENO, err_msg, indx);
	free(err_msg);
}

/**
 * print_exec_prog - add the name of the executable file to the error
 *
 * @buff: buffer where the output string will be stored
 * @exec: the name of the executable file
 * @n: error number to append to the output string
 *
 * Return: the last index of the resulting string
 */
unsigned int print_exec_prog(char *buff, char *exec, int n)
{
	unsigned int indx;

	for (indx = 0; exec[indx]; indx++)
		buff[indx] = exec[indx];

	buff[indx++] = ':';
	buff[indx++] = ' ';
	buff[indx++] = n + '0';
	buff[indx++] = ':';
	buff[indx++] = ' ';

	return (indx);
}
