#include "monty.h"

/**
 * free_data - Frees a type data_t structure
 */
void free_data(void)
{
	free(data.command);
	free_stack(&(data.stack));
	fclose(data.file);
}

/**
 * free_stack - Frees a type stack_t doubly linked list.
 * @stack: list to free.
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr;

	if (*stack == NULL)
		return;

	ptr = *stack;
	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}

