#include "monty.h"

/**
 * print_all_stack_values - Prints all values in a stack.
 * @head: Pointer to the head of the stack.
 * @counter: Unused parameter.
 *
 * Description: This function prints all the values in a stack, starting from
 * the top of the stack (head). The counter parameter is unused.
 */

void print_all_stack_values(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	(void)counter;

	if (current == NULL)
	{
		return;
	}

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
