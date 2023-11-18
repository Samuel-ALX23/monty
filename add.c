#include "monty.h"

/**
 * _add - adds the first two nodes of the stack
 * @stack: stack pointer provided by main
 * @line_num: line number for error reporting
 *
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	sum = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_num);
	(*stack)->n = sum;
}
