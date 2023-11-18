#include "monty.h"

/**
 * swap - swaps data from top to previous
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;
	int tmp_data = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	tmp_data = tmp->n;
	tmp->n = tmp_data;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_data;
}
