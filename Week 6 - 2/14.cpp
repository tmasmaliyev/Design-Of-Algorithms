#include <stdio.h>

int lowerTernarySearch(int* arr, int n, int target) {
	int l = 0, r = n, h, g;

	while (l < r) {
		h = l + (r - l) / 3;
		g = l + 2 * (r - l) / 3;

		if (arr[h] < target)
			l = h + 1;
		else if (arr[g] >= target)
			r = g;
		else {
			l = h;
			r = g;
		}
	}

	return l;
}

int upperTernarySearch(int* arr, int n, int target) {
	int l = 0, r = n, h, g;

	while (l < r) {
		h = l + (r - l) / 3;
		g = l + 2 * (r - l) / 3;

		if (arr[h] <= target)
			l = h + 1;
		else if (arr[g] > target)
			r = g;
		else {
			l = h;
			r = g;
		}
	}

	return l;
}

int main() {
	int n, q, target;

	scanf("%d %d", &n, &q);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < q; i++) {
		scanf("%d", &target);

		if (upperTernarySearch(arr, n, target) != lowerTernarySearch(arr, n, target))
			printf("YES\n");
		else
			printf("NO\n");
	}
}