#include "monty.h"

/**
 * opcode - function responsible for executing built-in instructions
 * @stack: stack pointer provided by main
 * @instruction: string containing the instruction to execute
 * @lineNumber: line number for error reporting
 *
 * Return: void
 */
void opcode(stack_t **stack, char *instruction, unsigned int lineNumber)
{
	int index = 0;

	instruction_t opcodes[] = INSTRUCTIONS;

	if (!strcmp(instruction, "stack"))
	{
		global.dataStructure = STACK;
		return;
	}
	if (!strcmp(instruction, "queue"))
	{
		global.dataStructure = QUEUE;
		return;
	}

	while (opcodes[index].opcode)
	{
		if (!strcmp(opcodes[index].opcode, instruction))
		{
			opcodes[index].function(stack, lineNumber);
			return;
		}
		index++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", lineNumber, instruction);
	exit(EXIT_FAILURE);
}
