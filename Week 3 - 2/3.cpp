#include <stdio.h>

int main() {
    int n, edgeLength, outgoingEdges;

    int arr[101][101];

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d ", &edgeLength);

        for (int j = 1; j <= edgeLength; j++) {
            scanf("%d ", &outgoingEdges);

            arr[i][outgoingEdges] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ", arr[i][j]);
        
        printf("\n");
    }
}