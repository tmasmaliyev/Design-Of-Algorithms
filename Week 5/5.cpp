#include <stdio.h>

class MergeSort {
public:
	int* segmentStorage;

	void helperSort(int* arr, int l, int r) {
		if (l == r) return;
	
		int mid = (l + r) / 2;

		helperSort(arr, l, mid);
		helperSort(arr, mid + 1, r);

		mergeSegmentation(arr, l, r);
	}

	void sort(int* arr, int l, int r) {
		this->segmentStorage = new int[r + 1];
		
		helperSort(arr, l, r);
	}

	void mergeSegmentation(int* arr, int l, int r) {
		int midBoundary = (l + r) / 2 + 1;
		int midInc = midBoundary;

		int leftInc = l;
		int pos = l;

		while (leftInc < midBoundary && midInc < r + 1) {
			if (arr[leftInc] < arr[midInc]) {
				segmentStorage[pos] = arr[leftInc];
				leftInc++;
			}
			else {
				segmentStorage[pos] = arr[midInc];
				midInc++;
			}

			pos++;
		}

		while (leftInc < midBoundary) {
			segmentStorage[pos] = arr[leftInc];
			pos++;
			leftInc++;
		}

		while (midInc < r + 1) {
			segmentStorage[pos] = arr[midInc];
			pos++;
			midInc++;
		}

		for (int i = l; i <= r; i++)
			arr[i] = segmentStorage[i];
	}
};

int main() {
	int n;

	scanf("%d", &n);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	MergeSort mS = MergeSort();
	mS.sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}