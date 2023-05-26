#include "monty.h"
/**
 *stack_sub- this subtracts the top from the second top of stack
 *@head: the head of the stack
 *@counter: code line position
 *Return: nothing
 */
void stack_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp_ptr;
	int result, nodes;

	temp_ptr = *head;

	for (nodes = 0; temp_ptr != NULL; nodes++)
		temp_ptr = temp_ptr->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(store.file);
		free(store.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp_ptr = *head;
	result = temp_ptr->next->n - temp_ptr->n;
	temp_ptr->next->n = result;
	*head = temp_ptr->next;
	free(temp_ptr);
}
