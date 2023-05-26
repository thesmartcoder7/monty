#include "monty.h"
/**
 *stack_rotr- this rotates the stack to the bottom
 *@head: the head of the stack
 *@counter: code line position
 *Return: nothing
 */
void stack_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp_ptr;

	temp_ptr = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (temp_ptr->next)
	{
		temp_ptr = temp_ptr->next;
	}

	temp_ptr->next = *head;
	temp_ptr->prev->next = NULL;
	temp_ptr->prev = NULL;
	(*head)->prev = temp_ptr;
	(*head) = temp_ptr;
}
