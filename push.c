#include "monty.h"

/**
 * push - adds an element to the stack
 * @stack: stack pointer provided by main
 * @lineNumber: line number for error reporting
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int lineNumber)
{
	const char *argument = global.argument;

	if (!isdigit(*argument)) {
		fprintf(stderr, "L%u: usage: push integer\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if (global.dataStructure == STACK)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
