#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int l = 0, r = n, h, g;

	while (l < r) {
		h = l + (r - l) / 3;
		g = l + 2 * (r - l) / 3;

		if (arr[h] < arr[g])
			l = h + 1;
		else if (arr[h] >= arr[g])
			r = g;
	}

	printf("%d", arr[l]);
}