#include "monty.h"


void f_rotate_left(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current_node = *stack, *new_head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	new_head = (*stack)->next;
	new_head->prev = NULL;

	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}

	current_node->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = current_node;
	(*stack) = new_head;
}
