#include "monty.h"

/**
 * pchar - prints the character representation of the integer at the top of the stack
 * @stack: stack pointer provided by main
 * @lineNumber: line number for error reporting
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int lineNumber)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
		return;
	}
	if (!isascii((*stack)->n))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", lineNumber);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
