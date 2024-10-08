#include <stdio.h>

int repr(int *&arr, int v) {
    if (v == arr[v]) return v;
    
    return arr[v] = repr(arr, arr[v]);
}

void makeUnion(int *&arr, int fromEdge, int outEdge) {

    int reprL = repr(arr, fromEdge);
    int reprR = repr(arr, outEdge);

    if (reprL != reprR) arr[reprL] = reprR;
}

int main() {
    int n, s, m, fromEdge, outEdge, totalRepr = 0;

    scanf("%d %d %d\n", &n, &s, &m);

    int *arr = new int[n + 1];

    for (int i = 1; i <= n; i++)
        arr[i] = i;
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &fromEdge, &outEdge);

        makeUnion(arr, fromEdge, outEdge);
    }

    for (int i = 1; i <= n; i++)
        if (arr[i] == i) totalRepr++;

    printf("%d\n", totalRepr - 1);
}