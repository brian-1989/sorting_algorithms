#include "sort.h"

/**
 * selection_sort - that sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 * @array: the pointer at array.
 * @size: number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, temp = 0, temp_2 = 0;
	bool flag = true;

	for (; i < size - 1; i++)
	{
		temp = i;
		flag = false;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
				temp = j, flag = true;
		}
		if (flag == true)
			temp_2 = array[i], array[i] = array[temp],
			array[temp] = temp_2, print_array(array, size);
	}
}
