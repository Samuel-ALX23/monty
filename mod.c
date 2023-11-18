#include "monty.h"

/**
 * mod - computes the remainder of the division
 * @stack: stack pointer provided by main
 * @line_num: line number for error reporting
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_num)
{
	int remainder;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	remainder = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = remainder;
}
