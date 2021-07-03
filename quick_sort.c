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
	int pivot = right;

	int i = left, j = right - 1;

	while(i <= j)
	{
		if(arr[i] <= arr[pivot])
		{
			i++;
			continue;	
		}

		if(arr[j] > arr[pivot])
		{
			j--;
			continue;
		}
	
		swap(&arr[i], &arr[j]);
	}

	swap(&arr[pivot], &arr[i]);

	return i;
}


void sort(int *arr, int left, int right)
{
	if(left < right)
	{
		int pivot = partition(arr, left, right);

		sort(arr, left, pivot - 1);
		sort(arr, pivot + 1, right);
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

