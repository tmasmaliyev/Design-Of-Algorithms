#include <stdio.h>

int lowerBound(int* arr, int n, int target) {
	int l = 0, r = n, mid;

	while (l < r) {
		mid = l + (r - l) / 2;

		if (target <= arr[mid])
			r = mid;
		else
			l = mid + 1;
	}

	return l;
}

int upperBound(int* arr, int n, int target) {
	int l = 0, r = n, mid;

	while (l < r) {
		mid = l + (r - l) / 2;

		if (target < arr[mid])
			r = mid;
		else
			l = mid + 1;
	}

	return l;
}

int main() {
	int n, q, searchVal;

	scanf("%d %d", &n, &q);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < q; i++) {
		scanf("%d", &searchVal);

		if (lowerBound(arr, n, searchVal) != upperBound(arr, n, searchVal))
			printf("YES\n");
		else
			printf("NO\n");
	}
}