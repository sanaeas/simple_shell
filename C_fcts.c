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

/**
 * own_strcmp - Compares two strings lexicographically
 *
 * @str1: The first string to compare
 * @str2: The second string to compare
 *
 * Return: An integer less than, equal to, or greater than 0
 *         if str1 is found, respectively, to be less than, to match,
 *         or be greater than str2.
 */
int own_strcmp(char *str1, char *str2)
{
	/* Iterate through each character in the strings while they are equal */
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char*)str1 - *(unsigned char*)str2);
}

/**
 * array_len - Calculates the length of an array of strings
 *
 * @str: The array of strings
 *
 * Return: The length of the array
 */
size_t array_len(char **str)
{
	size_t len;

	/* Iterate through the array until reaching a NULL pointer */
	for (len = 0; str[len]; len++)
		;

	return (len + 1);
}
