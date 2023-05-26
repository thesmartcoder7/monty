#include "monty.h"
/**
 * stack_addnode - this adds a node to the head stack
 * @head: the head of the stack
 * @n: new_value
 * Return: nothing
 */
void stack_addnode(stack_t **head, int n)
{
	stack_t *new_node, *temp_store;

	temp_store = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (temp_store)
		temp_store->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
