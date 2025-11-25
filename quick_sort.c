#include <stdio.h>

void	swap(int *a, int *b){
	int	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int array[], int low, int high){
	int	pivot = array[high];
	printf("Pivot elegido: %d\n", pivot);  // <- Aquí imprimimos
	int	i = low - 1;

	for (int j = low; j <= high - 1; j++){
		if (array[j] <= pivot){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int array[], int low, int high){
	if (low < high){
		int	p = partition(array, low, high);
		printf("Pivot colocado en posición %d: %d\n", p, array[p]);
		quick_sort(array, low, p - 1);
		quick_sort(array, p + 1, high);
	}
}

int	main(void)
{
	int	array[] = {2, 4, 1, 5, 7, 19, 3, 6, -4, -8, 8, 0};
	int	array_size = sizeof(array) / sizeof(array[0]);

	printf("Lista desordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");

	quick_sort(array, 0, array_size - 1);

	printf("Lista ordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
