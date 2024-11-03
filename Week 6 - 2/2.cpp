#include <stdio.h>
#include <cmath>

double f(double x, int a, int b, int c, int d) {
	return a * (x * x * x) + b * (x * x) + c * (x) + d;
}

int main() {
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	double l = -1, r = 1, e = 1e-7, mid, leftVal, rightVal, midVal;

	while (f(l, a, b, c, d) * f(r, a, b, c, d) > 0) {
		l *= 2;
		r *= 2;
	}

	while (r - l > e) {
		mid = (l + r) / 2;

		//leftVal = f(l, a, b, c, d);
		midVal = f(mid, a, b, c, d);
		rightVal = f(r, a, b, c, d);

		if (midVal * rightVal > 0) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	printf("%.9f", l);
}