#include <stdio.h>
#include <vector>
#include <cstring>

bool isCyclic(std::vector<std::vector<int>> adjecencyList, int v, int parent, bool *visited, int n) {
    int neighbour;
    visited[v] = true;

    for (int i = 0; i < adjecencyList[v].size(); i++) {
        neighbour = adjecencyList[v][i];

        if (!visited[neighbour]) {
            if (isCyclic(adjecencyList, neighbour, v, visited, n)) {
                visited[v] = false;
                return true;
            }
        }
        else if (parent != neighbour) {
            visited[v] = false;
            return true;
        }
    }

    visited[v] = false;

    return false;
}

int main() {
    int n, total = 0, val;
    std::vector<std::vector<int>> adjecencyList;
    
    scanf("%d\n", &n);

    bool *visited = new bool[n + 1];
    std::memset(visited, 0, (n + 1) * sizeof(bool));

    adjecencyList.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &val);

            if (val == 1)
                adjecencyList[i].push_back(j);

            total+= val;
        }
    }

    if (n - 1 == total / 2) {
        for (int i = 1; i <= n; i++) {
            if (isCyclic(adjecencyList, i, -1, visited, n)) {
                printf("NO");
                return 0;
            }
            // for (int i = 1; i <= n; i++) {
            //     printf("%d ", visited[i]);
            // }
            // printf("\n");
        }

        printf("YES");
    }
    else
        printf("NO");
}