#include "monty.h"

/**
 * free_stack - Frees all elements of a stack
 * @stack: A pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
