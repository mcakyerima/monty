#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char opcode[10];
	int value;
	int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack);
		}

		line_number++;
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
