#include "monty.h"

/**
 * o_add - Function that adds the two top elements
 * @stack: Pointer to stack
 * @line_number: Line number of the file being executed
 *
 * Return: Void
 */
void o_add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next->n = sum;
	(*stack)->prev = NULL;
	free(temp);
}
