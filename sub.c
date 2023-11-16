#include "monty.h"
/**
 *f_sub- sustration
 *@head: stack head
 *@counter: line_number
 *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *mar;
	int sam, nodes;

	mar = *head;
	for (nodes = 0; mar != NULL; nodes++)
		mar = mar->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	mar = *head;
	sam = mar->next->n - mar->n;
	mar->next->n = sam;
	*head = mar->next;
	free(mar);
}
