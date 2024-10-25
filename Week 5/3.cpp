#include <stdio.h>

void mergeSegments(int* arr1, int n, int* arr2, int m) {
	
	int* arr = new int[n + m];

	int leftInc1 = 0, leftInc2 = 0;
	int pos = 0;

	while (leftInc1 < n && leftInc2 < m) {
		if (arr1[leftInc1] < arr2[leftInc2]) {
			arr[pos] = arr1[leftInc1];
			leftInc1++;
		}
		else {
			arr[pos] = arr2[leftInc2];
			leftInc2++;
		}
		
		pos++;
	}

	while (leftInc1 < n) {
		arr[pos] = arr1[leftInc1];
		leftInc1++;
		pos++;
	}

	while (leftInc2 < m) {
		arr[pos] = arr2[leftInc2];
		leftInc2++;
		pos++;
	}

	for (int i = 0; i < n + m; i++)
		printf("%d ", arr[i]);
}

int main() {
	int n, m;
	int* arr1, * arr2;

	scanf("%d", &n);
	arr1 = new int[n];
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr1[i]);

	scanf("%d", &m);
	arr2 = new int[m];

	for (int i = 0; i < m; i++)
		scanf("%d", &arr2[i]);
	
	mergeSegments(arr1, n, arr2, m);
}