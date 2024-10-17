#include <stdio.h>

int main() {
    int n;
    int fromEdge, outEdge;
    int maxDegree = 0;

    int arr[100001];
    scanf("%d\n", &n);

    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &fromEdge, &outEdge);

        arr[fromEdge]++;
        arr[outEdge]++;
    }

    for (int i = 1; i <= n; i++){
        printf("%d ", arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (maxDegree < arr[i])
            maxDegree = arr[i];
    }

    printf("%d\n", maxDegree + 1);
}