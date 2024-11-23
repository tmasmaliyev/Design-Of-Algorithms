#include <stdio.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#define INF 0x3F3F3F3F

struct HeapComparator {
	bool operator()(const std::pair<int, int> a, const std::pair<int, int> b) const {
		return a.second > b.second;
	}
};

std::unordered_map<int, std::vector<int>> adjecencyList;
std::map<std::pair<int, int>, int> weights;

int main() {
	int n, m, s, f;
	int v_from, v_to, w, d;

	scanf("%d %d", &n, &m);

	scanf("%d %d", &s, &f);

	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v_from, &v_to, &w);

		adjecencyList[v_from].push_back(v_to);
		adjecencyList[v_to].push_back(v_from);

		weights[{v_from, v_to}] = w;
		weights[{v_to, v_from}] = w;
	}

	std::vector<int> dist(n + 1, INF);
	std::vector<int> predecessor(n + 1, -1);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, HeapComparator> pq;
	std::pair<int, int> tmp;

	pq.push({ s, 0 });

	dist[s] = 0;

	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();

		v_from = tmp.first;
		d = tmp.second;

		if (d > dist[v_from]) continue;

		for (auto v : adjecencyList[v_from]) {
			if (d + weights[{v_from, v}] < dist[v]) {
				dist[v] = d + weights[{v_from, v}];
				predecessor[v] = v_from;

				pq.push({ v, dist[v] });
			}
		}
	}

	if (dist[f] == INF) {
		printf("%d", -1);

		return 0;
	}

	std::vector<int> route = { f };

	printf("%d\n", dist[f]);

	while (f != s) {
		f = predecessor[f];

		route.push_back(f);
	}

	for (int i = route.size() - 1; i >= 0; i--)
		printf("%d ", route[i]);
}