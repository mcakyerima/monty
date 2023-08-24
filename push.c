#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number in the Monty file
 */

void push(stack_t **stack, unsigned int line_number)
{
    /* Read integer argument from Monty file */
	char *argument = /* ... (Read argument from file) ... */;

	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

    /* Convert argument to integer */
	int value = atoi(argument);

    /* Create a new stack node */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
