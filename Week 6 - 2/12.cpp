#include <stdio.h>
#include <algorithm>
#include <cmath>

#define EPS 1e-10

double f(double x, double y, double d) {
	double a = std::sqrt(x * x - d * d);
	double b = std::sqrt(y * y - d * d);

	return (a * b) / (a + b);
}

int main() {
	double x, y, c;

	while (scanf("%lf %lf %lf", &x, &y, &c) == 3) {

		double l = 0, r = std::min(x, y), mid, cVal;

		while (r - l > EPS) {
			mid = l + (r - l) / 2;

			cVal = f(x, y, mid);

			if (cVal <= c)
				r = mid;
			else
				l = mid;
		}

		printf("%.3f\n", l);
	}
}