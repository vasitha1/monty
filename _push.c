#include "monty.h"


/**
 * push - function that adds an element to a dynamic stack
 * @element: element to be added
 * @stack: Stack of values
 *
 * Return: Null
 */
void push(stack_t **stack, char *element)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(element);
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - function that prints elements in stack from LIFO
 * @stack: Stack of values
 *
 * Return: void
 */
void pall(stack_t *stack)
{
	stack_t *temp = stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
