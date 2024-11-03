#include <stdio.h>
#include <algorithm>

#define ll long long

ll lowerBound(ll* arr, ll n, ll target) {
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

ll upperBound(ll* arr, ll n, ll target) {
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

void initArr(ll*& arr, ll n) {
	for (ll i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	std::sort(arr, arr + n);

	//for (int i = 0; i < n; i++)
	//	printf("%d\n", arr[i]);
	//printf("\n\n");
}

int main() {
	ll n, ans = 0;

	scanf("%lld", &n);

	ll* a = new ll[n];
	ll* b = new ll[n];
	ll* c = new ll[n];
	
	initArr(a, n);
	initArr(b, n);
	initArr(c, n);

	for (ll i = 0; i < n; i++) {
		ll lSize = lowerBound(a, n, b[i]);
		ll rSize = n - upperBound(c, n, b[i]);

		ans += lSize * rSize;
	}

	printf("%lld", ans);
}