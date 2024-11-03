#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a % b);
}

int lcd(int a, int b) {
	int tmp;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	return (a * b) / gcd(a, b);
}

int f(int x, int a, int b) {
	return (x / a) + (x / b) - (x / lcd(a, b));
}

int main() {
	int n, a, b;

	scanf("%d %d %d", &a, &b, &n);
	
	int l = 0, r = 1e9, mid;

	while (l < r) {
		mid = l + (r - l) / 2;

		if (f(mid, a, b) < n)
			l = mid + 1;
		else
			r = mid;
	}

	printf("%d\n", l);
}