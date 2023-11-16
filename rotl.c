#include "monty.h"
/**
 *f_rotl- rotates the stack to the top
 *@head: stack head
 *@counter: line_number
 *Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *mar;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	mar = (*head)->next;
	mar->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = mar;
}
