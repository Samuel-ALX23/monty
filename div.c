#include "monty.h"

/**
 * _div - divides the next top value by the top value
 * @stack: stack pointer provided by main
 * @line_num: line number for error reporting
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_num)
{
	int quotient;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	quotient = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = quotient;
}
