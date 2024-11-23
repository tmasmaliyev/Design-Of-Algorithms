#include <stdio.h>

#define EPS 1e-10

double f(double x, double a, double b) {
	return x * x + a * x + b;
}

int main() {
	double a, b;

	scanf("%lf %lf", &a, &b);

	double l = -100, r = 100, h, g, eVal;

	while (r - l > EPS) {
		h = l + (r - l) / 3;
		g = l + 2 * (r - l) / 3;

		if (f(h, a, b) <= f(g, a, b))
			r = g;
		else
			l = h;
	}

	printf("%.2f", l);
}