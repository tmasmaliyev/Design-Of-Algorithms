#include <stdio.h>
#include <algorithm>

#define MIN_VAL 0 
#define MAX_VAL  0x7FFFFFFFFFFFFFFF    
#define ll long long

bool fTest(ll* arr, ll n, ll x) {
	ll incVal = x;

	for (ll i = 0; i < n; i++) {
		if (incVal < arr[i]) return false;
		incVal++;
	}

	return true;
}

ll f(ll* arr, ll n, ll x) {
	ll incVal = x;
	ll ans = 0;

	for (ll i = 0; i < n; i++) {
		ans += incVal - arr[i];
		incVal++;
	}

	return ans;
}

int main() {
	ll n;
	scanf("%lld", &n);

	ll* arr = new ll[n];
	ll maxVal = MIN_VAL;

	for (ll i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);

		if (arr[i] > maxVal)
			maxVal = arr[i];
	}

	ll l = arr[0], r = maxVal, mid;

	while (l < r) {
		mid = l + (r - l) / 2;
		
		if (!fTest(arr, n, mid))
			l = mid + 1;
		else {
			r = mid;
		}
	}
	printf("%lld", f(arr, n, l));
}