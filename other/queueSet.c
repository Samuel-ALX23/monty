#include "monty.h"

/**
 * set_lifi_to_queue - Sets the lifi flag to 1.
 * @head: Pointer to the head pointer of the stack.
 * @lineNumber: Line number parameter (unused).
 *
 * Description: This function sets the lifi flag in the bus structure to 1.
 */

void set_lifi_to_queue(stack_t **head, unsigned int lineNumber)
{
  (void)head;
  (void)lineNumber;
  bus.lifi = 1;
}
