#include "monty.h"

/**
 * is_digit - checks if a character is a digit
 * @character: character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int is_digit(char character)
{
	return character >= '0' && character <= '9';
}

/**
 * is_number - checks if a string is a valid number
 * @string: string to check
 *
 * Return: 1 if the string is a valid number, 0 otherwise
 */
int is_number(char *string)
{
	if (!string)
	{
		return (0);
	}

	if (*string == '-')
	{
		string++;
	}

	while (*string)
	{
		if (!is_digit(*string))
		{
			return (0);
		}
		string++;
	}

	return (1);
}
