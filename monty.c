#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \t\n");
		char *argument = strtok(NULL, " \t\n");

		if (opcode == NULL)
			continue;
		instruction_t instructions[] = {
			{"push", push},
			{"pall", pall},
			{NULL, NULL}
		};

		int i;

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}

		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
