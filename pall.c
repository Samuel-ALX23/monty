#include "monty.h"

/**
 * pall - prints the stack
 * @stack: stack pointer provided by main
 * @ignoredLineNumber: unused line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int ignoredLineNumber)
{
  (void) ignoredLineNumber;

  print_stack(*stack);
}
