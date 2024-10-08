#include <stdio.h>

int repr(int *arr, int v) {

    while (v != arr[v])
        v = arr[v];
    
    return v;
}

void makeUnion(int *&arr, int fromEdge, int outEdge) {
    int reprL = repr(arr, fromEdge);
    int reprR = repr(arr, outEdge);

    if (reprL != reprR)
        arr[reprL] = reprR;
}

int main() {
    int n, m, fromEdge, outEdge, totalRepr = 0;

    scanf("%d %d\n", &n, &m);

    int *arr = new int[n + 1];

    for (int i = 1; i <= n; i++)
        arr[i] = i;
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &fromEdge, &outEdge);

        makeUnion(arr, fromEdge, outEdge);
    }

    for (int i = 1; i <= n; i++)
        if (arr[i] == i) totalRepr++;

    if (totalRepr == 1) printf("YES");
    else printf("NO");
}