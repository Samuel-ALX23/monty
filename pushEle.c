#include "monty.h"


void pushElement(stack_t **stackHead, unsigned int lineNumber)
{
	int value, index = 0, isInvalid = 0;

	if (bus.argument)
	{
		if (bus.argument[0] == '-')
		{
			index++;
		}

		for (; bus.argument[index] != '\0'; index++)
		{
			if (bus.argument[index] < '0' || bus.argument[index] > '9')
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
			freeStack(*stackHead);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: Invalid input. Expected integer.\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		freeStack(*stackHead);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.argument);

	if (bus.stackIsEmpty)
	{
		addNode(stackHead, value);
	}
	else
	{
		addQueue(stackHead, value);
	}
}
