#include "monty.h"

void subtract_top_two_elements(stack_t **head, unsigned int lineNumber)
{
	stack_t *node1, *node2;
	int result;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	node1 = *head;
	node2 = node1->next;

	result = node2->n - node1->n;
	node2->n = result;

	*head = node2;
	free(node1);
}
