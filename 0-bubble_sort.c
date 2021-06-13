#include "sort.h"

/**
 *bubble_sort - function that sorts an array of integers in
 *ascending order using the Bubble sort algorithm
 * @array: the pointer at array
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0;
	int temp = 0;

	for ( ; i < size ; i++)
	{
		for ( ; j < size - 1 ; j++)
		{
			if (array[j] > array[j + 1])
				temp = array[j], array[j] = array[j + 1],
				array[j + 1] = temp,
				print_array(array, size);
		}
		j = 0;
	}
}
