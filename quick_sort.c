#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int * arr, int left, int right)
{
	int pivot = right;							// Take the last index as the pivot

	int i = left, j = right - 1;						// Create iterators which point to the left index and the last index excluding the pivot 

	while(i <= j)								// Iterate until the left iterator is equal to or less than right iterator
	{
		if(arr[i] <= arr[pivot])					// Check if the elements at the left of the pivot are smaller or equal to the pivot element. If not mark the position
		{								// of the iterator
			i++;
			continue;	
		}

		if(arr[j] > arr[pivot])						// Check if the elements at the right of the pivot are larger than the pivot element. If not mark the position of the 
		{								// iterator
			j--;
			continue;
		}
	
		swap(&arr[i], &arr[j]);						// Swap the contents at the left and the right iterator
	}

	swap(&arr[pivot], &arr[i]);						// Swap the contents of the 'i' index and the pivot. The 'i'th position is the exact position where the pivot element 
										// should be in the sorted list. Return the 'i'th index.
	return i;
}


void sort(int *arr, int left, int right)
{
	if(left < right)
	{
		int pivot = partition(arr, left, right);			// Find the pivot index. This value at this position is as should be in the sorted array

		sort(arr, left, pivot - 1);					// Call for quick sort in the left partition
		sort(arr, pivot + 1, right);					// Call for quick sort in the right partition
	}
}

int main()
{
	int arr[5] = {5,0,5,2,0};
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

