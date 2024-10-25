#include <stdio.h>

#define ll long long

ll mergeSegments(ll*& arr, ll*& segment, ll l, ll r) {
	ll leftInc = l;

	ll midStatic = (l + r) / 2 + 1;
	ll midInc = midStatic;
	ll pos = l;

	ll ans = 0;

	while (leftInc < midStatic && midInc < r + 1) {
		if (arr[leftInc] <= arr[midInc])
			segment[pos] = arr[leftInc++];
		else {
			segment[pos] = arr[midInc];

			ans += midInc - pos;
			midInc++;
		}
		pos++;
	}

	while (leftInc < midStatic)
		segment[pos++] = arr[leftInc++];

	while (midInc < r + 1)
		segment[pos++] = arr[midInc++];

	for (ll i = l; i <= r; i++)
		arr[i] = segment[i];

	return ans;
}

ll helperSwap(ll*& arr, ll*& segment, ll l, ll r) {
	if (l == r) return 0;

	ll mid = (l + r) / 2;
	
	ll leftSwap = helperSwap(arr, segment, l, mid);
	ll rightSwap = helperSwap(arr, segment, mid + 1, r);

	ll bothSwap = mergeSegments(arr, segment, l, r);

	return leftSwap + rightSwap + bothSwap;
}

ll optimumSwap(ll*& arr, ll l, ll r) {
	ll* segment = new ll[r + 1];

	return helperSwap(arr, segment, l, r);
}

int main() {
	ll n;
	
	while (scanf("%lld", &n) == 1) {
		if (n <= 0) break;

		ll* arr = new ll[n];
		
		for (ll i = 0; i < n; i++)
			scanf("%lld", &arr[i]);
		
		//printf("\n");
		//for (ll i = 0; i < n; i++)
		//	printf("%d ", arr[i]);

		printf("%lld\n", optimumSwap(arr, 0, n - 1));
	}
}