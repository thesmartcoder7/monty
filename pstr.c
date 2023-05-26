#include "monty.h"
/**
 * stack_pstr - this will print the string starting at the top
 * @head: the head of the stack
 * @counter: code line position
 * Return: nothing
 */
void stack_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;

	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}

	printf("\n");
}
