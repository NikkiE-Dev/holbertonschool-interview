#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome- checks if a linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	if (!*head || !*head)
		return (1);
	else
		return (palindrome_check(head, *head));
}

/**
 * palindrome_check- checks if a linked list is a palindrome
 * @initial: first linked list
 * @reverse: reversed linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int palindrome_check(listint_t **initial, listint_t *reverse)
{
	if (!reverse || !*initial)
		return (1);
	if (palindrome_check(initial, reverse->next) && (*initial)->n == reverse->n)
	{
		*initial = (*initial)->next;
		return (1);
	}
		else
			return (0);
}
