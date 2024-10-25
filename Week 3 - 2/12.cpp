#include <stdio.h>

int main() {
    int n, m;
    int adjecencyMatrix[101][101];

    int fromEdge, outEdge;

    scanf("%d %d\n", &n, &m);

    bool hasNonDistinctPair = false;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &fromEdge, &outEdge);

        adjecencyMatrix[fromEdge][outEdge] = adjecencyMatrix[outEdge][fromEdge] = 1;
    }

    bool res = true;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            res &= adjecencyMatrix[i][j];
    }

    if (res)
        printf("YES");
    else
        printf("NO");
}