#include <stdio.h>
#include <vector>
#include <algorithm>

#define ll long long
std::vector<ll> v;

#define MAX_PRIME_NUM (ll)(1e6 + 1)

bool primes[MAX_PRIME_NUM];
ll HIGH = (ll)1e12;


void findAllPrimes() {
	ll ans, degree;

	for (ll i = 2; i * i <= MAX_PRIME_NUM; i++) {
		if (!primes[i]) {
			for (ll j = i * i; j <= MAX_PRIME_NUM; j += i) {
				primes[j] = true;
			}
		}
	}

	for (ll i = 2; i <= MAX_PRIME_NUM; i++) {
		if (!primes[i]) {
			ans = i * i, degree = 2;
			v.push_back(ans);

			while (ans <= HIGH / i) {
				ans *= i;
				degree++;
				
				v.push_back(ans);
			}
		}
	}
	std::sort(v.begin(), v.end());
}

ll upperBound(ll target) {
	ll l = 0, r = v.size(), mid;

	while (l < r) {
		mid = l + (r - l) / 2;

		if (v[mid] <= target)
			l = mid + 1;
		else
			r = mid;
	}

	return l;
}

int main() {
	findAllPrimes();
	
	ll n, low, high;

	scanf("%lld", &n);

	for (ll i = 0; i < n; i++) {
		scanf("%lld %lld", &low, &high);

		//printf("%lld ", upperBound(high));
		//printf("%lld ", upperBound(low - 1));

		printf("%lld\n", upperBound(high) - upperBound(low - 1));
	}
}