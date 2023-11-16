#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @current: Pointer to the current node of the stack.
 *
 * Description: This function frees a stack by iterating through each node
 * and freeing the memory allocated for it.
 */

void free_stack(stack_t *current)
{
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
