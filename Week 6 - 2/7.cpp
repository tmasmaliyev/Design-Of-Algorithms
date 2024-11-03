#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define LL_MAX 0x7FFFFFFFFFFFFFFF

ll pow(ll base, ll degree) {
	ll res = 1;

	for (ll i = 0; i < degree; i++)
		res *= base;

	return res;
}

ll f(ll x, ll y) {
	return pow(2, x) * pow(3, y);
}

bool isOverflow(ll x, ll y) {
	ll leftSide = pow(2L, x);
	ll rightSide = pow(3L, y);

	if (leftSide <= LL_MAX / rightSide) return false;

	return true;
}

ll lowerBound(std::vector<ll>& arr, ll target) {
	ll n = arr.size();
	ll l = 0, r = n, mid;

	while (l < r) {
		mid = l + (r - l) / 2;

		if (arr[mid] < target)
			l = mid + 1;
		else
			r = mid;
	}

	return l;
}

ll upperBound(std::vector<ll>& arr, ll target) {
	ll n = arr.size();
	ll l = 0, r = n, mid;

	while (l < r) {
		mid = l + (r - l) / 2;

		if (arr[mid] <= target)
			l = mid + 1;
		else
			r = mid;
	}

	return l;
}

int main() {
	ll x, y;

	std::vector<ll> v;

	ll log2Applied = std::log(LL_MAX) / std::log(2L);
	ll log3Applied = std::log(LL_MAX) / std::log(3L);

	for (ll i = 0; i <= log2Applied; i++) {
		for (ll j = 0; j <= log3Applied; j++) {
			if (!isOverflow(i, j))
				v.push_back(f(i, j));
			else break;
		}	
	}


	std::sort(v.begin(), v.end());
	//for (ll i = 0; i < v.size(); i++)
	//	printf("%lld\n", v[i]);
	
	while (scanf("%lld %lld", &x, &y) == 2) {
		printf("%lld\n", upperBound(v, y) - upperBound(v, x - 1));
	}
}