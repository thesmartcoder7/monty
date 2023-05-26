#include "monty.h"
/**
 *stack_rotl- this rotates the stack to the top
 *@head: the head of the stack
 *@counter: code line position
 *Return: nothing
 */
void stack_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *ptr = *head, *new_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	new_head = (*head)->next;
	new_head->prev = NULL;

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = *head;
	(*head)->next = NULL;
	(*head)->prev = ptr;
	(*head) = new_head;
}
