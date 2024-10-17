#include <stdio.h>

int main() {
    int n, m;
    int fromEdge, outEdge;

    scanf("%d %d\n", &n, &m);

    int arr[101][101];
    bool hasMultiEdge = false;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d\n", &fromEdge, &outEdge);

        arr[fromEdge][outEdge]++;

        if (arr[fromEdge][outEdge] > 1) 
            hasMultiEdge = true;
    }

    if (hasMultiEdge)
        printf("YES");
    else
        printf("NO");
}