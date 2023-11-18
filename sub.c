#include "monty.h"

/**
 * _sub - subtracts the top two values from the stack
 * @stack: stack pointer provided by main
 * @lineNumber: line number for error reporting
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int lineNumber)
{
	int difference;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	difference = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, lineNumber);
	(*stack)->n = difference;
}
