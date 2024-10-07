#include <stdio.h>
#include <vector>

int main() {
    int n;
    int fromEdge, outEdge;

    int totalDisconnect = 0;

    std::vector<int> adjecencyList;
    scanf("%d\n", &n);

    adjecencyList.resize(n + 1);

    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &fromEdge, &outEdge);

        adjecencyList[fromEdge]++;
        adjecencyList[outEdge]++;
    }

    for (int i = 1; i <= n; i++) {
        if (adjecencyList[i] > 2)
            totalDisconnect+= adjecencyList[i] - 2;
    }

    printf("%d\n", totalDisconnect);
}