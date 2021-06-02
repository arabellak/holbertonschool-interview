#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* find_listint_loop - Finds loop in linked list.
* @head: head of list.
* Return:
*   Null - if there is no loop
*   or Address of node where the loop starts.
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *quick, *slow;

	if (head == NULL)
	{
		return (NULL);
	}

	quick = head;
	slow = head;

	while (quick != NULL && quick->next != NULL && quick->next->next != NULL)
	{
		slow = slow->next;
		quick = quick->next->next;

		if (slow == quick)
		{
			slow = head;
			while (slow != quick)
			{
				slow = slow->next;
				quick = quick->next;
			}
			return (quick);
		}
	}
	return (NULL);
}
