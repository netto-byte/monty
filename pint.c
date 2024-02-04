#include "monty.h"
/**
 * pint - prints the top
 * @stack: Pointer to a stack
 * @line_number: command index in a monty file
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_data();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
