#include <stdio.h>

void merge(int *arr, int left, int right, int mid)
{
	int temp[right - left + 1];			// Create a temp array
	int i = left, j = mid + 1, k = 0;		// Create iterators

	// Compare elements of both the left and right parts, if left element is smaller, place it in temp or else place the right element. Note the increment operation
	while(i <= mid && j <= right)
	{
		if(arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
			k++;
		}

		else
		{
			temp[k] = arr[j];
			j++;
			k++;
		}

	}

	// Place the uncompared left elements if any in the temp
	while(i <= mid)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}

	// Place the uncompared right elements if any in the temp
	while(j <= right)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}

	// copy the elements from the temp to the destination array
	for(i = left; i <= right; i++)
		arr[i] = temp[i - left];

}

void sort(int *arr, int left, int right)
{
	if(left < right)	// Carry until left index is smaller than the right index
	{
		int mid = left + (right - left)/2;

		sort(arr, left, mid);		// sort the left array
		sort(arr, mid + 1, right);	// sort the right array
		merge(arr, left, right, mid);	// merge both the arrays
	}
}

int main()
{
	int arr[5] = {5,4,33,2,1};
	int size = 5;


	printf("Input Array:\n");

	for(int i = 0; i < size; i++)
		printf("%d\t", arr[i]);

	printf("\n\n");

	sort(arr, 0, size - 1);

	printf("Sorted Array:\n");

        for(int i = 0; i < size; i++)
                printf("%d\t", arr[i]);

	printf("\n\n");
	return 0;
}
