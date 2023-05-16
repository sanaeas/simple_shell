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

/**
 * own_strcpy - Copies a string
 *
 * @copy: The destination buffer to copy the string into
 * @str: The source string to be copied
 *
 * Return: Pointer to the destination buffer
 */
char *own_strcpy(char *copy, char *str)
{
	/* Iterate through each character in the source string */
	while (*str)
	{
		*copy = *str;
		copy++;
		str++;
	}
	/* Add null character at the end */
	*copy = '\0';

	return (copy);
}
