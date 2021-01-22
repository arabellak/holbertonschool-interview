# include "lists.h"

/**
*back - Reverses list
*@head: head.
*Return: Nothing
*/

void back(listint_t **head)
{
	listint_t *tmp = *head;
	listint_t *p = NULL;
	listint_t *n = NULL;

	while (tmp)
	{
		n = tmp->next;
		tmp->next = p;
		p = tmp;
		tmp = n;
	}
	*head = p;
}

/**
*center - Center
*@head: Head
*Return: Right
*/

listint_t *center(listint_t **head)
{
	listint_t *right = *head;
	listint_t *left = *head;

	while (left && left->next)
	{
		right = right->next;
		left = left->next->next;
	}
	return (right);
}

/**
*is_palindrome - Checks if a singly linked list is palindrome.
*@head: head
*Return: 0 if not palindrome
*          1 if it is
*/

int is_palindrome(listint_t **head)
{
	listint_t *cent;
	int i = 0;

	if (*head == NULL)
		return (1);

	cent = center(head);

	back(&cent);

	while (cent)
	{
		if (cent->n != (*head)->n)
			return (0);

		*head = (*head)->next;
		cent = cent->next;
		i = 1;
	}

	if (i == 1)
	{
		return (1);
	}

	return (0);
}
