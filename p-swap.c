#include "monty.h"


void swap_top_two_elements(stack_t **head, unsigned int lineNumber)
{
	stack_t *topNode, *secondNode, *tempNode;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	topNode = *head;
	secondNode = topNode->next;

	tempNode = topNode;
	topNode = secondNode;
	secondNode = tempNode;

	topNode->prev = secondNode->prev;
	if (secondNode->prev)
	{
		secondNode->prev->next = topNode;
	}
	else
	{
		*head = topNode;
	}
	topNode->next = secondNode->next;
	if (secondNode->next)
	{
		secondNode->next->prev = topNode;
	}
	else
	{
		secondNode->next = NULL;
	}
	secondNode->prev = topNode;
	secondNode->next = topNode->prev;
	if (topNode->prev)
	{
		topNode->prev->next = secondNode;
	}
	else
	{
		*head = secondNode;
	}
	topNode->prev = secondNode;
}
