#include "monty.h"

/**
 * queue_node - adds a node to a stack_t stack in queue_node
 * @stack_head: stack head pointer
 * @newNodeData: data for the new node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */

stack_t *queue_node(stack_t **stack_head, const int newNodeData)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	stack_t *current = *stack_head;

	if (!newNode)
	{
		free(newNode);
		return (NULL);
	}

	newNode->n = newNodeData;

	if (!*stack_head)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		*stack_head = newNode;
		return (newNode);
	}

	while (current)
	{
		if (!current->next)
		{
			newNode->next = NULL;
			newNode->prev = current;
			current->next = newNode;
			break;
		}
		current = current->next;
	}

	return (newNode);
}

/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack_head: stack head pointer
 * @newNodeData: data for the new node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */

stack_t *add_node(stack_t **stack_head, const int newNodeData)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newNode);
		return (NULL);
	}

	newNode->n = newNodeData;

	newNode->next = *stack_head;
	newNode->prev = NULL;
	if (*stack_head)
		(*stack_head)->prev = newNode;
	*stack_head = newNode;
	return (newNode);
}

/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */

size_t print_stack(const stack_t *stack)
{
	size_t count = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		count++;
	}
	return (count);
}

/**
 * free_stack - frees a dlistint_t linked list
 * @stack: stack head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}
