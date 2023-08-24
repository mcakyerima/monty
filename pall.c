#include "monty.h"

/**
 * pall - Prints all values on the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number; /* Unused parameter */

	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
