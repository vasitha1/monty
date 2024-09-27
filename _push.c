#include "monty.h"


/**
 * o_push - function that adds an element to a dynamic stack
 * @line_number: Tells which line is being executed
 * @stack: Stack of values
 *
 * Return: Null
 */
void o_push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	argument = strtok(NULL, "\n\t\r ");

	if (argument == NULL || check_arg(argument) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n",
			line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(argument);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * o_pall - function that prints elements in stack from LIFO
 * @stack: Stack of values
 * @line_number: Tells which line is being executed
 *
 * Return: void
 */
void o_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)(line_number);

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
