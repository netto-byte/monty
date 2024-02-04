#include "monty.h"

/**
 * pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to the stack to print
 * @line_number: current command index
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void)line_number;

	if (*stack == NULL)
		return;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
