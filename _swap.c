#include "monty.h"

/**
 * o_swap - Swaps the two top elements of a stack
 * @stack: Pointer to stack
 * @line_number: of the file being executed
 *
 * Return: Void
 */
void o_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
		line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
