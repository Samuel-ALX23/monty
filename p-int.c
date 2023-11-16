#include "monty.h"


void print_integer(stack_t **head, unsigned int instruction_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't print integer, stack empty\n", instruction_number);
		free_stack(*head);

		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
