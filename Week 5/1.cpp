#include <stdio.h>

int main() {
	int n, singleVal, minValue = 1e5 + 1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &singleVal);

		if (singleVal < minValue) minValue = singleVal;
	}

	printf("%d\n", minValue);
}