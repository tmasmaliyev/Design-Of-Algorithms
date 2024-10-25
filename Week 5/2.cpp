#include <stdio.h>

class MergeSort {
public:
	int* segmentStorage;

	void helperSort(int*& arr, int l, int r) {
		
		if (l == r) return;

		int mid = (l + r) / 2;

		helperSort(arr, l, mid);
		helperSort(arr, mid + 1, r);

		mergeSegments(arr, l, r);
	}
	void sort(int*& arr, int l, int r) {
		this->segmentStorage= new int[r + 1];

		helperSort(arr, l, r);
	}

	void mergeSegments(int*& arr, int l, int r) {
		
		int midBoundary = (l + r) / 2 + 1;
		int midInc = midBoundary;
		int startPos = l;
		int leftInc = l;

		while (leftInc < midBoundary && midInc < r + 1) {
			if (arr[leftInc] < arr[midInc]) {
				this->segmentStorage[startPos] = arr[leftInc];
				leftInc++;
			}
			else {
				this->segmentStorage[startPos] = arr[midInc];
				midInc++;
			}

			startPos++;
		}

		while (leftInc < midBoundary) {
			this->segmentStorage[startPos] = arr[leftInc];
			leftInc++;
			startPos++;
		}

		while (midInc < r + 1) {
			this->segmentStorage[startPos] = arr[midInc];
			midInc++;
			startPos++;
		}

		for (int i = l; i <= r; i++) 
			arr[i] = this->segmentStorage[i];

	}
};

int main() {
	int n;
	
	scanf("%d\n", &n);

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		
	MergeSort mS = MergeSort();

	mS.sort(arr, 0, n - 1);
	
	printf("%d\n", arr[0] + arr[n - 1]);
}