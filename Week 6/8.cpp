#include <stdio.h>
#include <algorithm>

int partition(int* arr, int l, int r) {

	int lp = l - 1;
	int rp = r + 1;
	int mid = (l + r) / 2;

	int piv = arr[l] + arr[mid] + arr[r] - std::min({ arr[l], arr[mid], arr[r] }) - std::max({ arr[l], arr[mid], arr[r] });
	int tmp;

	while (1) {
		do rp--; while (arr[rp] < piv);
		do lp++; while (arr[lp] > piv);

		if (lp < rp) {
			tmp = arr[lp];
			arr[lp] = arr[rp];
			arr[rp] = tmp;
		}
		else return rp;
	}
}

int kthValue(int* arr, int l, int r, int k) {
	if (l == r) return arr[l];

	int q = partition(arr, l, r);

	if (k <= q)
		return kthValue(arr, l, q, k);
	else
		return kthValue(arr, q + 1, r, k);
}

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (k > n)
		printf("%d", -1);
	else
		printf("%d", kthValue(arr, 0, n - 1, k - 1));
}