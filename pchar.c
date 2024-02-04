#include "monty.h"
/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: pointer to a stack head
 * @line_number: line_number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_data();
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_data();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
