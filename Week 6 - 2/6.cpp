#include <stdio.h>
#include <iostream>

#define ll long long

ll gcd(ll a, ll b) {
	if (b == 0) return a;

	return gcd(b, a % b);
}

ll lcd(ll a, ll b) {
	return (a * b) / gcd(a, b);
}

template<typename... Args>
ll lcd(ll firstEl, Args... args) {
	
	ll ans = firstEl;

	((ans = lcd(ans, args)), ...);

	return ans;
}

ll f(ll x, ll a, ll b, ll c) {
	return (x / a) + (x / b) + (x / c) - (x / lcd(a, b)) - (x / lcd(a, c)) - (x / lcd(b, c)) + (x / lcd(a, b, c));
}

int main() {
	ll a, b, c, n;

	scanf("%lld %lld %lld %lld", &a, &b, &c, &n);

	ll l = 0, r = 1e9, mid;

	while (l < r) {
		mid = l + (r - l) / 2;

		if (f(mid, a, b, c) < n)
			l = mid + 1;
		else
			r = mid;
	}

	printf("%lld", l);
}
