#include <stdio.h>

void heapify(int *&arr, int i, int n) {

    int maxVal = arr[i], tmp;
    int maxValIndex = i;

    if (2 * i <= n && maxVal < arr[2 * i]) {
        maxVal = arr[2 * i];
        maxValIndex = 2 * i;
    }

    if (2 * i + 1 <= n && maxVal < arr[2 * i + 1]) {
        maxVal = arr[2 * i + 1];
        maxValIndex = 2 * i + 1;
    }
    
    if (maxVal != arr[i]) {
        tmp = arr[i];
        arr[i] = maxVal;
        arr[maxValIndex] = tmp;

        heapify(arr, maxValIndex, n);
    }
}

int main() {
    int n;

    scanf("%d\n", &n);

    int *arr = new int[n + 1];

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    for (int i = n / 2; i >= 1; i--)
        heapify(arr, i, n);
    
    for (int i = 1; i <= n; i++) 
        printf("%d ", arr[i]);
}