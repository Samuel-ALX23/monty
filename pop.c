#include "monty.h"

/**
 * pop - removes the top element from the stack
 * @stack: stack pointer provided by main
 * @lineNumber: line number for error reporting
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temporaryNode;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	temporaryNode = (*stack)->next;
	free(*stack);
	*stack = temporaryNode;

	if (!*stack)
	{
		return;
	}

	(*stack)->prev = NULL;
}
