#include <stdio.h>

int main() {
    int n, m;
    int fromEdge, outEdge;
    int adjecencyMatrix[101][101];

    scanf("%d %d\n", &n, &m);

    bool hasDistinctPair = true;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &fromEdge, &outEdge);

        adjecencyMatrix[fromEdge][outEdge]++;
    }

    for (int i = 1; i <= n; i++) {
        bool hasNoDistinctEdge = true;

        for (int j = 1; j <= n; j++) {
            if (i != j && adjecencyMatrix[i][j] + adjecencyMatrix[j][i] != 1) {
                hasNoDistinctEdge = false;            
                break;
            }
        }

        if (!hasNoDistinctEdge) {
            printf("NO");
            return 0;
        }
    }
}