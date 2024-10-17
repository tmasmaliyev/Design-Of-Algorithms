#include <stdio.h>

int repr(int *&arr, int v) {

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
    int n, val, ans = 0;

    scanf("%d\n", &n);

    int *arr = new int[n + 1];

    for (int i = 1; i <= n; i++)
        arr[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &val);

            if (val == 1)
                makeUnion(arr, i, j);
        }
    }

    for (int i = 1; i <= n; i++)
        if (arr[i] == i) ans++;
    
    printf("%d\n", ans);
}