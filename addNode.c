#include "monty.h"

/**
 * insert_node - Inserts a new node at the head of the stack.
 * @head: Pointer to the head pointer of the stack.
 * @data: Data value to be stored in the new node.
 *
 * Description: This function creates a new node, populates it with the given
 * data, and inserts it at the head of the stack.
 */

void insert_node(stack_t **head, int data)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		printf("Error: Unable to allocate memory for new node\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = data;

	newNode->next = *head;
	newNode->prev = NULL;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		(*head)->prev = newNode;
	}

	*head = newNode;
}
