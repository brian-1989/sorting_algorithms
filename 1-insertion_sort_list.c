#include "sort.h"

/**
 * insertion_sort_list - this function  sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: double pointer to the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *temp_2 = NULL, *temp_3 = NULL;
	listint_t *temp_4 = NULL, *temp_5 = NULL;

	temp = *list, temp_2 = (*list)->next;
	while (temp != NULL && temp_2 != NULL)
	{
		if (temp->n > temp_2->n)
		{
			if (temp_2->next == NULL)
				temp_3 = temp->prev, temp_3->next = temp_2, temp_2->prev = temp_3,
				temp->next = NULL, temp->prev = temp_2, temp_2->next = temp,
				temp = temp_2, temp_2 = temp->next, print_list(*list);
			else
				temp_4 = temp_2->next, temp_3 = temp->prev, temp_3->next = temp_2,
				temp_2->prev = temp_3, temp_2->next = temp, temp->prev = temp_2,
				temp->next = temp_4, temp_4->prev = temp, temp = temp_2,
				temp_2 = temp->next, print_list(*list);
			temp_5 = temp_2, temp_2 = temp_5->prev, temp = temp_2->prev;
			while (temp != NULL && temp_2 != NULL)
			{
				if (temp->n > temp_2->n)
				{
					if (temp->prev == NULL)
						temp_3 = temp_2->next, temp_2->prev = NULL, temp_2->next = temp,
						temp->next = temp_3, temp->prev = temp_2, temp_3->prev = temp,
						temp_2 = temp, temp = temp_2->prev,
						*list = temp, print_list(*list);
					else
						temp_4 = temp_2->next, temp_3 = temp->prev, temp_3->next = temp_2,
						temp_2->prev = temp_3, temp_2->next = temp, temp->prev = temp_2,
						temp->next = temp_4, temp_4->prev = temp, temp = temp_2,
						temp_2 = temp->next, print_list(*list);
				}
				temp_2 = temp, temp = temp_2->prev;
			}
			temp = temp_5->prev, temp_2 = temp_5, temp_5 = NULL;
		}
		temp = temp->next, temp_2 = temp_2->next;
	}
}
