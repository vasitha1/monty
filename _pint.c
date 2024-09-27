#include "monty.h"

/**
 * o_pint - Frunction prints the value at the top of the stack
 * @stack: Pointer to stack
 * @line_number: Pointer to line number
 *
 * Return: NULL;
 */
void o_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
