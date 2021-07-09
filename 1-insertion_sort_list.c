#include "sort.h"

/**
 *traveling_the_list_from_right_to_left - function that travel the
 *list from right to left.
 *@list: double pointer to the linked list.
 *@temp: first pointer to compare.
 *@temp_2: second pointer to compare.
 *Return: the pointer where the smaller number was changed,
 *when compared.
 */
listint_t *traveling_the_list_from_right_to_left(listint_t **list,
	listint_t *temp, listint_t *temp_2)
{
	listint_t *temp_3 = NULL, *temp_4 = NULL;

	if (temp->prev == NULL)
		temp_3 = temp_2->next, temp_2->prev = NULL, temp_2->next = temp,
		temp->next = temp_3, temp->prev = temp_2, temp_3->prev = temp,
		temp_2 = temp, temp = temp_2->prev, *list = temp, print_list(*list);
	else
		temp_4 = temp_2->next, temp_3 = temp->prev, temp_3->next = temp_2,
		temp_2->prev = temp_3, temp_2->next = temp, temp->prev = temp_2,
		temp->next = temp_4, temp_4->prev = temp, temp = temp_2,
		temp_2 = temp->next, print_list(*list);
	return (temp);
}

/**
 *traveling_the_list_from_left_to_right - function that travel the
 *list from left to right.
 *@list: double pointer to the linked list.
 *@temp: first pointer to compare.
 *@temp_2: second pointer to compare.
 *Return: the pointer where the smaller number was changed,
 *when compared.
 */
listint_t *traveling_the_list_from_left_to_right(listint_t **list,
	listint_t *temp, listint_t *temp_2)
{
	listint_t *temp_3 = NULL, *temp_4 = NULL;

	if (temp->prev == NULL && temp_2->next == NULL)
		*list = temp_2, temp_2->next = temp, temp_2->prev = NULL,
		temp->next = NULL, temp->prev = temp_2, temp = temp_2,
		temp_2 = temp->next, print_list(*list);
	else if (temp->prev == NULL)
		*list = temp_2, temp_3 = temp_2->next, temp_2->prev = NULL,
		temp_2->next = temp, temp->next = temp_3, temp->prev = temp_2,
		temp_3->prev = temp, temp = temp_2, temp_2 = temp->next,
		print_list(*list);
	else if (temp_2->next == NULL)
		temp_3 = temp->prev, temp_3->next = temp_2, temp_2->prev = temp_3,
		temp->next = NULL, temp->prev = temp_2, temp_2->next = temp,
		temp = temp_2, temp_2 = temp->next, print_list(*list);
	else
		temp_4 = temp_2->next, temp_3 = temp->prev, temp_3->next = temp_2,
		temp_2->prev = temp_3, temp_2->next = temp, temp->prev = temp_2,
		temp->next = temp_4, temp_4->prev = temp, temp = temp_2,
		temp_2 = temp->next, print_list(*list);
	return (temp);
}

/**
 * insertion_sort_list - this function  sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: double pointer to the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *temp_2 = NULL;
	listint_t *temp_5 = NULL, *temp_return_1 = NULL, *temp_return_2 = NULL;

	if (list == NULL || *list == NULL)
		return;
	temp = *list, temp_2 = (*list)->next;
	while (temp != NULL && temp_2 != NULL)
	{
		if (temp->n > temp_2->n)
		{
			temp_return_1 = traveling_the_list_from_left_to_right(list, temp, temp_2);
			temp = temp_return_1, temp_2 = temp_return_1->next;
			temp_5 = temp_2, temp_2 = temp_5->prev, temp = temp_2->prev;
			while (temp != NULL && temp_2 != NULL)
			{
				if (temp->n > temp_2->n)
				{
					temp_return_2 = traveling_the_list_from_right_to_left(list, temp, temp_2);
					temp = temp_return_2, temp_2 = temp_return_2->next;
				}
				temp_2 = temp, temp = temp_2->prev;
			}
			temp = temp_5->prev, temp_2 = temp_5, temp_5 = NULL;
		}
		temp = temp->next, temp_2 = temp_2->next;
	}
}
