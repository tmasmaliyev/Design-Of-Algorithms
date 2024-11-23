#include <stdio.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

#define INF 0x3FFFFFFFFFFFF
#define ll long long

std::unordered_map<
	ll, 
	std::vector<std::pair<ll, ll>>
> adjecencyList;


struct HeapComparator {
	bool operator()(const std::pair<ll, ll>& a, const std::pair<ll, ll>& b) const {
		return a.second > b.second;
	}
};

void djikstra(ll st, std::vector<ll> &dist) {
	ll v_from, v, d, w;

	std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, HeapComparator> pq;
	std::pair<ll, ll> tmp;

	pq.push({ st, 0 });

	dist[st] = 0;
	
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();

		v_from = tmp.first;
		d = tmp.second;

		if (d > dist[v_from]) continue;

		for (auto p : adjecencyList[v_from]) {
			v = p.first;
			w = p.second;

			if (d + w < dist[v]) {
				dist[v] = d + w;

				pq.push({ v, dist[v] });
			}
		}
	}
}

int main() {
	ll n, m, k;
	ll v_from, v_to, w, d;
	ll bestDistance = 0;

	scanf("%lld %lld %lld", &n, &m, &k);

	std::vector<ll> bestRoute(k + 1);

	for (ll i = 1; i <= k; i++) 
		scanf("%lld", &bestRoute[i]);


	for (ll i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &v_from, &v_to, &d);

		adjecencyList[v_from].push_back({ v_to, d });
		adjecencyList[v_to].push_back({ v_from, d });
	}
	
	for (ll i = 1; i < k; i++) {
		d = INF;

		for (auto x : adjecencyList[bestRoute[i]]) {
			if (x.first == bestRoute[i + 1])
				d = std::min(x.second, d);
		}
		bestDistance += d;
	}

	for (ll i = 1; i < k; i++) {
		v_from = bestRoute[i];
		v_to = bestRoute[i + 1];

		std::vector<ll> dist(n + 1, INF);

		d = INF;

		for (auto x : adjecencyList[v_from]) {
			if (x.first == v_to)
				d = std::min(d, x.second);
		}


		adjecencyList[v_from].erase(
			std::remove(adjecencyList[v_from].begin(), adjecencyList[v_from].end(), std::make_pair(v_to, d)),
			adjecencyList[v_from].end()
		);

		adjecencyList[v_to].erase(
			std::remove(adjecencyList[v_to].begin(), adjecencyList[v_to].end(), std::make_pair(v_from, d)),
			adjecencyList[v_to].end()
		);

		djikstra(1, dist);

		adjecencyList[v_from].push_back({ v_to, d });
		adjecencyList[v_to].push_back({ v_from, d });
		
		printf("%lld\n", dist[n]);

		printf("%lld\n", bestDistance);

		if (dist[n] == bestDistance) {
			printf("yes");

			return 0;
		}

	}
	
	printf("no");
}
