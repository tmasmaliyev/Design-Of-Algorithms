#include <stdio.h>
#include <cmath>

const double PI = std::atan(1.0) * 4;
#define EPS 1e-13

double f(double r, int n) {

	double degree = 0, tmpVal;

	for (int i = 1; i <= n; i++) {
		tmpVal = (2 * r * r - i * i) / (2 * r * r);
		degree += std::acos(tmpVal) * (180 / PI);
	}

	return degree;
}

int main() {
	int n;

	scanf("%d", &n);

	double l = (double)n / 2, r = n * n, mid, degreeAll;

	while (r - l > EPS) {
		mid = l + (r - l) / 2;

		degreeAll = f(mid, n);
		//printf("%f %.5f\n", mid, degreeAll);

		if (degreeAll <= 360)
			r = mid;
		else
			l = mid;
	}

	printf("%.8f", l);
}