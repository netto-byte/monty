#include "monty.h"
/**
  *rotl - rotates the stack to the top
  *@stack: pointer to a stack head
  *@line_number: line_number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *bottom = *stack;

	(void)line_number;
	if (*stack == NULL || data.size == 1)
		return;

	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	ptr->next = bottom;
	bottom->next = NULL;
	bottom->prev = ptr;
}
