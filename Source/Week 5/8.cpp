#include <stdio.h>

class MergeSort {
public:
	int* segmentArr;
	int mergeSegment(int*& arr, int l, int r) {
		int leftInc = l;
		int midStatic = (l + r) / 2 + 1;
		int midInc = midStatic;
		
		int ansSwap = 0;
		int pos = l;

		while (leftInc < midStatic && midInc < r + 1) {
			if (arr[leftInc] <= arr[midInc]) {
				segmentArr[pos] = arr[leftInc];
				leftInc++;
			}
			else {
				segmentArr[pos] = arr[midInc];
				midInc++;

				ansSwap += midStatic - leftInc;
			}

			pos++;
		}

		while (leftInc < midStatic) {
			segmentArr[pos] = arr[leftInc];
			leftInc++;
			pos++;
		}
		while (midInc < r + 1) {
			segmentArr[pos] = arr[midInc];
			pos++;
			midInc++;
		}

		for (int i = l; i <= r; i++)
			arr[i] = segmentArr[i];
		
		return ansSwap;
	}
	
	int helperOptimalSwap(int*& arr, int l, int r) {
		if (l == r) return 0;

		int mid = (l + r) / 2;

		int leftSwap = helperOptimalSwap(arr, l, mid);
		int rightSwap = helperOptimalSwap(arr, mid + 1, r);

		return leftSwap + rightSwap + mergeSegment(arr, l, r);
	}
	int optimalSwap(int*& arr, int l, int r) {
		segmentArr = new int[r + 1];

		return helperOptimalSwap(arr, l, r);
	}
};

int main() {
	int t, n;
	int* arr;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);

		arr = new int[n];

		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		MergeSort mS = MergeSort();
		printf("Optimal train swapping takes %d swaps.\n", mS.optimalSwap(arr, 0, n - 1));
	}
}