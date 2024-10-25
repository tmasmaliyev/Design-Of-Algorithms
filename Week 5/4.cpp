#include <stdio.h>

void initializeArray(int*& arr, int length) {

	for (int i = 0; i < length; i++)
		scanf("%d", &arr[i]);
}

void mergeSegments(int* arr1, int n, int* arr2, int m, int* arr3, int k) {
	
	int leftInc1 = 0, leftInc2 = 0, leftInc3 = 0;
	int pos = 0;
	int* arr = new int[n + m + k];

	while (leftInc1 < n && leftInc2 < m && leftInc3 < k) {
		if (arr1[leftInc1] <= arr2[leftInc2] && arr1[leftInc1] <= arr3[leftInc3]) {
			arr[pos] = arr1[leftInc1];
			leftInc1++;
		}
		else if (arr2[leftInc2] <= arr1[leftInc1] && arr2[leftInc2] <= arr3[leftInc3]) {
			arr[pos] = arr2[leftInc2];
			leftInc2++;
		}
		else if (arr3[leftInc3] <= arr1[leftInc1] && arr3[leftInc3] <= arr2[leftInc2]) {
			arr[pos] = arr3[leftInc3];
			leftInc3++;
		}

		pos++;
	}

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

	while (leftInc1 < n && leftInc3 < k) {
		if (arr1[leftInc1] < arr3[leftInc3]) {
			arr[pos] = arr1[leftInc1];
			leftInc1++;
		}
		else {
			arr[pos] = arr3[leftInc3];
			leftInc3++;
		}

		pos++;
	}

	while (leftInc2 < m && leftInc3 < k) {
		if (arr2[leftInc2] < arr3[leftInc3]) {
			arr[pos] = arr2[leftInc2];
			leftInc2++;
		}
		else {
			arr[pos] = arr3[leftInc3];
			leftInc3++;
		}

		pos++;
	}

	while (leftInc1 < n) {
		arr[pos] = arr1[leftInc1];
		pos++;
		leftInc1++;
	}
	
	while (leftInc2 < m) {
		arr[pos] = arr2[leftInc2];
		pos++;
		leftInc2++;
	}

	while (leftInc3 < k) {
		arr[pos] = arr3[leftInc3];
		pos++;
		leftInc3++;
	}

	for (int i = 0; i < n + m + k; i++)
		printf("%d ", arr[i]);
}

int main() {
	int* arr1, * arr2, * arr3;
	int n, m, k;

	scanf("%d", &n);
	arr1 = new int[n];

	initializeArray(arr1, n);

	scanf("%d", &m);
	arr2 = new int[m];

	initializeArray(arr2, m);

	scanf("%d", &k);
	arr3 = new int[k];

	initializeArray(arr3, k);

	mergeSegments(arr1, n, arr2, m, arr3, k);
}