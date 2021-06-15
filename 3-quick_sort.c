#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 * @array: the pointer at array.
 * @size: number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	int low_array = 0, high_array = 0;

	high_array = size - 1;
	if (array != NULL && size != '\0')
		the_original_quick_sort(array, low_array, high_array, size);
}

/**
 * the_original_quick_sort - function that is implemented
 * to be able to use recursion.
 * @array: the pointer at array.
 * @low_array: first number of the array.
 * @high_array: last number of the array.
 * @size: number of elements in the array.
 */
void the_original_quick_sort(int *array, int low_array,
	int high_array, size_t size)
{
	int temp = 0;

	if (low_array < high_array)
	{
		temp = division_array(array, low_array, high_array, size);
		the_original_quick_sort(array, low_array, temp - 1, size);
		the_original_quick_sort(array, temp + 1, high_array, size);
	}
}

/**
 * division_array - function that is implemented to divide the array.
 * @array: the pointer at array.
 * @low_array: first number of the array.
 * @high_array: last number of the array.
 * @size: number of elements in the array.
 * Return: the number of the position of pivot.
 */
int division_array(int *array, int low_array, int high_array, size_t size)
{
	int i = low_array - 1, j = 0, temp = 0, pivot = array[high_array];

	/* Loop to travel the divided part */
	for (j = low_array; j < high_array; j++)
	{
		/* condition to compare the pivot with all the elemnts of the divided part */
		if (array[j] < pivot)
		{
			i++;
			temp = array[i], array[i] = array[j], array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1], array[i + 1] = array[high_array],
	array[high_array] = temp;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}
