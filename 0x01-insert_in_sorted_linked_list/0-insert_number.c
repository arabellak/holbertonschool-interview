#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Head.
 * @number: Number.
 * Return: Null if it failed or address of new node.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *baby_node, *tmp;

	if (head == NULL)
		return (NULL);

	tmp = *head;
	baby_node = malloc(sizeof(listint_t));
	if (baby_node == NULL)
		return (NULL);

	baby_node->n = number;
	if (*head == NULL)
	{
		baby_node->next = NULL;
		*head = baby_node;
	}
	else
	{
		if (number < tmp->n)
		{
			baby_node->next = tmp;
			*head = baby_node;
			return (*head);
		}
		else
		{
			while (tmp->next != NULL)
			{
				if (tmp->n < number && tmp->next->n < number)
				{
					tmp = tmp->next;
				}
				else
				{
					baby_node->next = tmp->next;
					tmp->next = baby_node;
					break;
				}
			}
			if (tmp->next == NULL)
				return (add_nodeint_end(head, number));
		}
	}
    return (baby_node);
}
