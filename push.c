#include "monty.h"

/**
 * pushElement - Pushes an element onto the stack.
 * @stackHead: Pointer to the head of the stack.
 * @lineNumber: Line number where the push operation is performed.
 *
 * Description: This function pushes an element onto the stack. It expects the
 * element to be a valid integer.
 */
void pushElement(stack_t **stackHead, unsigned int lineNumber);
void pushElement(stack_t **stackHead, unsigned int lineNumber)
{
	int value, index = 0, isInvalid = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
		{
			index++;
		}

		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] < '0' || bus.arg[index] > '9')
			{
				isInvalid = 1;
				break;
			}
		}

		if (isInvalid)
		{
			fprintf(stderr, "L%d: Invalid input. Expected integer.\n", lineNumber);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stackHead);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: Invalid input. Expected integer.\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stackHead);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);

	if (bus.lifi == 0)
	{
		insert_node(stackHead, value);
	}
	else
	{
		set_lifi_to_queue(stackHead, value);
	}
}
