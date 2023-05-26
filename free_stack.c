#include "monty.h"
/**
* free_stack - this frees a doubly linked list
* @head: the head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *temp_ptr;

	temp_ptr = head;
	while (head)
	{
		temp_ptr = head->next;
		free(head);
		head = temp_ptr;
	}
}
