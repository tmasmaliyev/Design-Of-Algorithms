#include <stdio.h>
#include <cmath>

int main() {
	double c, e= 1e-7, val;

	scanf("%lf", &c);

	double l = 0, r = c, mid;

	while (r - l > e) {
		mid = (l + r) / 2;

		val = mid * mid + std::sqrt(mid);

		if (val <= c) {
			l = mid;
		}
		else if (val > c) {
			r = mid;
		}
	}

	printf("%.6f", l);
}