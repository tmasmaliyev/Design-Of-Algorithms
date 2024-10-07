#include <stdio.h>

int main() {
    int n, m;
    int st, end;

    int arr[101][101];

    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d\n", &st, &end);

        arr[st][end] = 1;
        arr[end][st] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            printf("%d ", arr[i][j]);
        
        printf("\n");
    }
}