#include "monty.h"


void rotate_right(stack_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	stack_t *last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = *head;
	(*head)->prev = last;
	(*head)->next = NULL;
	*head = last;
}
