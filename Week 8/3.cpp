#include <stdio.h>
#include <queue>
#include <unordered_map>
#include <map>
#include <vector>
#include <utility>

#define INF 0x3F3F3F

std::unordered_map<int, std::vector<int>> adjecencyList;
std::map<std::pair<int, int>, int> weights;

struct HeapComparator {
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
		return a.second > b.second;
	}
};

int main() {
	int n, m;
	int v_from, v_to, d;

	scanf("%d", &n);

	std::vector<int> fuelCost(n + 1);
	std::vector<int> dist(n + 1, INF);

	for (int i = 1; i <= n; i++)
		scanf("%d", &fuelCost[i]);

	scanf("%d", &m);
	
	// Exception can occur here if m == 0 or m == 1
	if (m == 0) {
		printf("%d", -1);

		return 0;
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &v_from, &v_to);

		adjecencyList[v_from].push_back(v_to);
		adjecencyList[v_to].push_back(v_from);

		weights[{v_from, v_to}] = fuelCost[v_from];
		weights[{v_to, v_from}] = fuelCost[v_to];
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, HeapComparator> pq;
	std::pair<int, int> tmp;

	pq.push({ 1, 0 });

	dist[1] = 0;

	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();

		v_from = tmp.first;
		d = tmp.second;

		if (d > dist[v_from]) continue;

		for (int v : adjecencyList[v_from]) {
			if (d + weights[{v_from, v}] < dist[v]) {
				dist[v] = d + weights[{v_from, v}];

				pq.push({ v, dist[v] });
			}
		}
	}

	if (dist[n] == INF) {
		printf("%d", -1);

		return 0;
	}

	printf("%d", dist[n]);
}