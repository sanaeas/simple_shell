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
