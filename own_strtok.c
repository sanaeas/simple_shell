#include "shell_header.h"

/**
 * own_strtok - A custom implementation of strtok function that splits a string
 *              into tokens based on a delimiter
 *
 * @str: the input string to be tokenized
 * @delim: delimiter string used for tokenization (spliting the string)
 *
 * Return: next token in the input string | NULL if there are no more tokens
 */
char *own_strtok(char *str, const char *delim)
{
	static char *last;
	char *token;

	if (str != NULL)
		last = str;
	token = last;

	while (*last != '\0')
	{
		if (is_delimiter(*last, delim))
		{
			*last = '\0';
			last++;
		}
		else
		{
			token = last;
			while (*last != '\0' && !is_delimiter(*last, delim))
				last++;
			if (*last != '\0')
			{
				*last = '\0';
				last++;
			}
			return (token);
		}
	}

	return (NULL);
}

/**
 * is_delimiter - Check if a character is a delimiter
 *
 * @c: The character to be checked
 * @delim: the delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}

	return (0);
}
