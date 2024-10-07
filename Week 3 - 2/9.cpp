#include <stdio.h>

int main() {
    int n, m;
    int arr[101];

    int fromEdge, outEdge;

    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d\n", &fromEdge, &outEdge);

        arr[fromEdge]++;
        arr[outEdge]++;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", arr[i]);
    }
}