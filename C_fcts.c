#include "shell_header.h"

/**
 * own_strlen - Calculates the length of a string
 *
 * @str: The string to calculate the length of
 *
 * Return: The length of the string
 */
int own_strlen(char *str)
{
	int length = 0; 

	if (str == NULL)
		return (0);
	/* Iterate through each character in the string until the null terminator */
	while (*str != '\0')
	{
		length++;
		str++;
	}

	return (length);
}
