#include "monty.h"
/**
 * pop - removes the top element of the sta
 * @stack: Pointer to a stack
 * @line_number: command index in a monty file
 * Return: no return
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_data();
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}
