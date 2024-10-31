#include <stdio.h>

int objectiveFunction(int x) {
	int terms[] = {132, 77, 1345, 1577};

	int res = 0, tmp, mod = 1743;

	for (int i = 3; i >= 0; i--) {
		tmp = 1;

		for (int j = 1; j <= i; j++) 
			tmp = (tmp * x) % mod;

		tmp = (tmp * terms[3 - i]) % mod;

		res = (res + tmp) % mod;
	}

	return res;
}

int partition(int* arr, int l, int r) {

	int lp = l - 1;
	int rp = r + 1;
	int piv = arr[l], tmp;

	while (1) {
		do rp--; while (arr[rp] > piv);
		do lp++; while (arr[lp] < piv);

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

	for (int i = 1; i <= n; i++) 
		arr[i - 1] = objectiveFunction(i);

	printf("%d", kthValue(arr, 0, n - 1, k - 1));
}