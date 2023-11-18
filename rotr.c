#include "monty.h"

/**
 * rotr - rotates the stack to the right by one element
 * @stack: stack pointer provided by main
 * @ignoredLineNumber: unused line number
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int ignoredLineNumber)
{
	(void) ignoredLineNumber;

	if (!stack || !*stack || !(*stack)->next)
	{
		return;
	}

	stack_t *bottomNode = *stack;
	stack_t *previousNode;

	while (bottomNode->next)
	{
		bottomNode = bottomNode->next;
	}

	previousNode = bottomNode->prev;
	bottomNode->next = *stack;
	bottomNode->prev = NULL;
	previousNode->next = NULL;
	(*stack)->prev = bottomNode;
	*stack = bottomNode;
}
