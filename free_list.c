#include "monty.h"

/**
 * free_dlistint - Function to free a doubly linked list
 * @head: Head pointer to the list
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
