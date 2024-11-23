#include <stdio.h>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>

#define INF 0x3F3F3F3F

std::unordered_map<int, std::vector<int>> adjecencyList;
std::map<std::pair<int, int>, int> weights;

int main() {
    int n, s, f;
    int w, d, v;

    scanf("%d %d %d", &n, &s, &f);
    std::vector<int> dist(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &w);

            if (i == j) continue;

            if (w == -1) continue;

            adjecencyList[i].push_back(j);
            weights[{i, j}] = w;
        }

        dist[i] = INF;
    }

    std::priority_queue<std::pair<int, int>> pq;
    std::pair<int, int> tmp;

    dist[s] = 0;

    pq.push({ s, 0 });

    while (!pq.empty()) {
        tmp = pq.top();
        pq.pop();

        v = tmp.first;
        d = tmp.second;

        if (d > dist[v]) continue;

        for (int v_go : adjecencyList[v]) {
            if (weights[{v, v_go}] == -1) continue;

            if (d + weights[{v, v_go}] < dist[v_go]) {
                dist[v_go] = d + weights[{v, v_go}];
                pq.push({ v_go, dist[v_go] });
            }
        }
    }

    if (dist[f] == INF)
        printf("%d", -1);

    else
        printf("%d", dist[f]);
}