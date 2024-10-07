#include <stdio.h>
#include <vector>

int main() {
    int n, val;

    scanf("%d\n", &n);

    std::vector<std::vector<int>> adjecencyList;
    adjecencyList.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d ", &val);

            if (val == 1) {
                adjecencyList[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", adjecencyList[i].size());

        for (int j = 0; j < adjecencyList[i].size(); j++)
            printf("%d ", adjecencyList[i][j]);
        
        printf("\n");
    }
}