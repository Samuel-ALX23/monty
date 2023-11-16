#include "monty.h"
/**
 *f_rotr- rotates the stack to the bottom
 *@head: stack head
 *@counter: line_number
 *Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *scan;

	scan = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (scan->next)
	{
		scan = scan->next;
	}
	scan->next = *head;
	scan->prev->next = NULL;
	scan->prev = NULL;
	(*head)->prev = scan;
	(*head) = scan;
}
