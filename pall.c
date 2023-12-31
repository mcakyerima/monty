#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 */
void pall(stack_t *stack)
{
	stack_t *current = stack;

	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
