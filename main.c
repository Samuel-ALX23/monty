#include "monty.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

int main(int argc, char *argv[])
{
	FILE *bytecodeFile;
	char *currentLine;
	size_t lineSize;
	ssize_t readBytes;
	stack_t *stack;
	unsigned int instructionNumber;

	if (argc != 2)
	{
		fprintf(stderr, "ERROR: Invalid usage. Correct usage: monty bytecode_file\n");
		exit(EXIT_FAILURE);
	}

	bytecodeFile = fopen(argv[1], "r");

	if (!bytecodeFile)
	{
		fprintf(stderr, "ERROR: Failed to open bytecode file '%s'\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	currentLine = NULL;
	lineSize = 0;
	stack = NULL;
	instructionNumber = 0;

	while ((readBytes = getline(&currentLine, &lineSize, bytecodeFile)) != -1)
	{
		instructionNumber++;

		process_instruction(currentLine, &stack, instructionNumber, bytecodeFile);

		free(currentLine);
		currentLine = NULL;
	}

	free_stack(stack);

	fclose(bytecodeFile);

	return 0;
}
