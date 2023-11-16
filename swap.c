#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *a;
	int des = 0, mar = 0;

	a = *head;
	while (a)
	{
		a = a->next;
		des++;
	}
	if (des < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	a = *head;
	des = a->n;
	a->n = a->next->n;
	a->next->n = mar;
}
