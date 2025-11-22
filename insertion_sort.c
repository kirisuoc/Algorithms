#include <stdio.h>

void	insertion_sort(int array[], int n){
	for (int i = 1; i <= n - 1; i++){
		int	j = i - 1;
		int	key = array[i];
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

int	main(void)
{
	int	array[] = {2, 4, 1, 5, 7, 19, 3, 6, -4, -8};
	int	array_size = sizeof(array) / sizeof(array[0]);

	printf("Lista desordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");

	insertion_sort(array, array_size);

	printf("Lista ordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
