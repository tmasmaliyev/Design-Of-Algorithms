#include <stdio.h>

int main() {
    int n, m;
    int arr[101];
    int fromEdge, outEdge, degreeByOneEdge = 0;

    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d\n", &fromEdge, &outEdge);

        arr[fromEdge]++;
        arr[outEdge]++;
    }

    degreeByOneEdge = arr[1];

    for (int i = 1; i <= n; i++) {
        if (degreeByOneEdge != arr[i]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
}