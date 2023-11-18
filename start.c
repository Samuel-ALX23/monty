#define _POSIX_C_SOURCE 200809L
#include "monty.h"

void file_error(char *filename);
void error_usage(void);
int globalStatus = 0;

/**
 * main - entry point
 * @argc: number of arguments passed to the program
 * @argv: array of arguments passed to the program
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t bufferLength = 0;
	char *buffer = NULL;
	char *token;
	stack_t *stack = NULL;
	unsigned int lineNumber = 1;

	global.dataStructure = STACK;
	if (argc != 2)
	{
		error_usage();
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		file_error(argv[1]);
	}

	while ((getline(&buffer, &bufferLength, file)) != -1)
	{
		if (globalStatus)
		{
			break;
		}

		if (*buffer == '\n')
		{
			lineNumber++;
			continue;
		}

		token = strtok(buffer, " \t\n");

		if (!token || *token == '#')
		{
			lineNumber++;
			continue;
		}

		global.argument = strtok(NULL, " \t\n");

		opcode(&stack, token, lineNumber);

		lineNumber++;
	}

	free(buffer);
	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}

/**
 * file_error - prints file error message and exits
 * @filename: name of the file that could not be opened
 *
 * Return: void
 */
void file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * error_usage - prints usage message and exits
 *
 * Return: void
 */
void error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
