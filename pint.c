#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: stack pointer provided by main
 * @lineNumber: line number for error reporting
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int lineNumber)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
		return;
	}

	printf("%d\n", (*stack)->n);
}
