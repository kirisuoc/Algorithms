#include <stdio.h>

void	swap(int *a, int *b){
	int	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i){
	int	largest = i;
	int	left = 2 * i + 1;
	int	right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i){
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heap_sort(int arr[], int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int	main(void)
{
	int	array[] = {2, 4, 1, 5, 7, 19, 3, 6, -4, -8, 8, 0, 65, -5};
	int	array_size = sizeof(array) / sizeof(array[0]);

	printf("Lista desordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");

	heap_sort(array, array_size);

	printf("Lista ordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
