#include "monty.h"


void dis_character(stack_t **head, unsigned int instruction_number)
{
	stack_t *current = *head;

	if (!current)
	{
		fprintf(stderr, "L%d: can't print character, stack empty\n", instruction_number);
		free_stack(*head);

		exit(EXIT_FAILURE);
	}

	if (current->n < 0 || current->n > 127)
	{
		fprintf(stderr, "L%d: can't print character, value out of range\n", instruction_number);
		free_stack(*head);

		exit(EXIT_FAILURE);
	}

	char character = (char)current->n;
	printf("%c\n", character);
}
