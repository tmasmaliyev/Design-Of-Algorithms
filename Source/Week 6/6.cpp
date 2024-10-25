#include <stdio.h>

int partition(int*& arr, int l, int r) {

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

int kthValue(int*& arr, int l, int r, int k) {

    if (l == r) return arr[l];


    int q = partition(arr, l, r);

    if (k <= q) return kthValue(arr, l, q, k);
    else if (k > q) return kthValue(arr, q + 1, r, k);
}

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
    printf("%d\n", kthValue(arr, 0, n - 1, k - 1));
}