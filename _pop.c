#include "monty.h"

/**
 * o_pop - Function that removes the first element of a linked list
 * @stack: Pointer to head of stack
 * @line_number: Keeps track of line number
 *
 * Return: NULL
 */
void o_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
