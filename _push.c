#include "monty.h"


/**
 * o_push - function that adds an element to a dynamic stack
 * @line_num: Tells which line is being executed
 * @stack: Stack of values
 *
 * Return: Null
 */
void o_push(stack_t **stack, unsigned int line_num)
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

	if (argument == NULL || (atoi(argument) == 0 && argument[0] != '0'))
	{
		fprintf(stderr, "L%u: usage: push integer\n",
			line_num);
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
 * @line_num: Tells which line is being executed
 *
 * Return: void
 */
void o_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;
	(void)(line_num);

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
