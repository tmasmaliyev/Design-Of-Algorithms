#include <stdio.h>

int partition(int *&arr, int l, int r) {
	
	int piv = arr[l], temp;
	int i = l - 1, j = r + 1;

	while (1) {
		do j--; while (arr[j] > piv);
		do i++; while (arr[i] < piv);

		if (i < j)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		else return j;
	}
}

void quickSort(int *&arr, int l, int r) {
	
	if (l == r) return;

	int q = partition(arr, l, r);

	quickSort(arr, l, q);
	quickSort(arr, q + 1, r);
}

int main() {
	int n;
	
	scanf("%d", &n);
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}