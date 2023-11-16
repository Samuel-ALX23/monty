#include "monty.h"



void handle_mudulo(stack_t **head, char *argument, unsigned int instruction_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", instruction_number);
		free_stack(*head);

		exit(EXIT_FAILURE);
	}

	current = *head;
	quotient = current->next->n % current->n;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", instruction_number);

		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current->next->n = quotient;

	*head = current->next;
	free(current);
}
