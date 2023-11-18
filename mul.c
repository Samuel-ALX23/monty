#include "monty.h"

/**
 * _mul - multiplies the next top value by the top value
 * @stack: stack pointer provided by main
 * @line_num: line number for error reporting
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	int product;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	product = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = product;
}
