#include <stdio.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#define INF 0x3FFFFFFFFFFFFFFF
#define ll long long

std::unordered_map<ll, std::vector<ll>> adjecencyList;
std::map<std::pair<ll, ll>, ll> weights;

struct HeapComparator {
	bool operator()(const std::pair<ll, ll>& a, const std::pair<ll, ll>& b) const {
		return a.second > b.second;
	}
};


int main() {
	ll n, v, d, cost;

	scanf("%lld", &n);

	std::vector<ll> platform(n + 1);
	std::vector<ll> dist(n + 1, INF);

	for (ll i = 1; i <= n; i++)
		scanf("%lld", &platform[i]);

	std::priority_queue < std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, HeapComparator> pq;
	std::pair<ll, ll> tmp;

	pq.push({ 1, 0 });

	dist[1] = 0;

	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();

		v = tmp.first;
		d = tmp.second;

		if (d > dist[v]) continue;

		for (ll v_to = 0; v_to <= n; v_to++) {
			cost = (v_to - v) * (v_to - v) * (platform[v_to] - platform[v]) * (platform[v_to] - platform[v]);

			if (d + cost < dist[v_to]) {
				dist[v_to] = d + cost;

				pq.push({ v_to, dist[v_to] });
			}
		}
	}

	printf("%lld", dist[n]);
}