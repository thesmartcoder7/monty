#include "monty.h"
/**
 * stack_queue - this prints the top
 * @head: the head of the stack
 * @counter: code line position
 * Return: nothing
 */
void stack_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	store.flag_change = 1;
}

/**
 * stack_enqueue - this adds a node to the tail stack
 * @n: new_value
 * @head: the head of the stack
 * Return: nothing
 */
void stack_enqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp_ptr;

	temp_ptr = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
	}

	new_node->n = n;
	new_node->next = NULL;

	if (temp_ptr)
	{
		while (temp_ptr->next)
			temp_ptr = temp_ptr->next;
	}

	if (!temp_ptr)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp_ptr->next = new_node;
		new_node->prev = temp_ptr;
	}
}
