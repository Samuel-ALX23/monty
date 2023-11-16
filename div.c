#include "monty.h"


void divide_elements(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int stack_length = 0, quotient;

	while (current)
	{
		current = current->next;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	quotient = current->next->n / current->n;

	current->next->n = quotient;

	*head = current->next;
	free(current);
}
