#include "monty.h"

/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack pointer provided by main
 * @ignoredLineNumber: unused line number
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int ignoredLineNumber)
{
	(void) ignoredLineNumber;

	stack_t *currentNode = *stack;

	while (currentNode)
	{
		if (currentNode->n <= 0 || currentNode->n > 127)
		{
			break;
		}
		putchar((char) currentNode->n);
		currentNode = currentNode->next;
	}
	putchar('\n');
}
