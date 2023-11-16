#include "monty.h"



void add_stack(stack_t **head, unsigned int counter)
{
	stack_t *top = *head;
	stack_t *current = *head;
	int length = 0, sum;
	stack_t *next;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	stack_t *next = top->next;

	sum = top->n + next->n;

	next->data = sum;

	*head = top->next;

	free(top);
}
