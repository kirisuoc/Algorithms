#include <stdio.h>
#include <stdlib.h>

void	merge(int array[], int left, int mid, int right){
	int	i = left;		// índice para la sublista izquierda
	int	j = mid + 1;	// índice para la sublista derecha
	int	k = 0;

	int	size = right - left + 1;
	int	*temp = malloc(size * sizeof(int));	// array temporal

	// Fusionar las dos mitades ya ordenadas
	while (i <= mid && j <= right){
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	// Copiar lo que reste de la mitad izquierda
	while (i <= mid){
		temp[k++] = array[i++];
	}

	// Copiar lo que reste de la mitad derecha
	while (j <= right)
		temp[k++] = array[j++];

	// Copiar el resultado al array original
	for (int p = 0; p < size; p++){
		array[left + p] = temp[p];
	}

	free(temp);
}

void	merge_sort(int array[], int left, int right){
	if (left >= right){
		return; // caso base: array de 1 elemento
	}

	int	mid = left + (right - left) / 2;

	merge_sort(array, left, mid);
	merge_sort(array, mid + 1, right);

	merge(array, left, mid, right);
}

int	main(void)
{
	int	array[] = {2, 4, 1, 5, 7, 19, 3, 6, -4, -8};
	int	array_size = sizeof(array) / sizeof(array[0]);

	printf("Lista desordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");

	merge_sort(array, 0, array_size - 1);

	printf("Lista ordenada: ");
	for (int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}
