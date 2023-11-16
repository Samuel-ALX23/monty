#include "monty.h"


void _string_dis(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n > 127 || current->n <= 0)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
