#include <stdio.h>

int main() {
    int n;

    int arr[100001];
    
    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d\n", &arr[i]);
    
    bool isHeap = true;

    for (int i = 1; i <= n / 2; i++) {
        if ((arr[i] > arr[2 * i]) || (2 * i + 1 <= n && arr[i] > arr[2 * i + 1])) {
            isHeap = false;
            break;
        }
    }

    if (!isHeap)
        printf("NO");
    
    else
        printf("YES");
}