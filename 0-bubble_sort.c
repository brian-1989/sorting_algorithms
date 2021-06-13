#include "sort.h"

/**
 *bubble_sort - function that sorts an array of integers in
 *ascending order using the Bubble sort algorithm
 * @array: the pointer at array
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int j = 0, temp = 0;
	bool flag_bubble = true;

	/* Loop tp validate the flag */
	while (flag_bubble != false)
	{
		flag_bubble = false;
		/* Loop that travel the array */
		for (j = 0 ; j < size - 1; j++)
		{
			/* Condition to compare twice positions of the array */
			if (array[j] > array[j + 1])
				temp = array[j], array[j] = array[j + 1],
				array[j + 1] = temp, flag_bubble = true,
				print_array(array, size);
		}
	}
}
