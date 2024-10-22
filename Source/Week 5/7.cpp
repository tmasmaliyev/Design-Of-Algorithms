#include <stdio.h>

class OlympiadProperties {
public:
	int id;
	int point;

	OlympiadProperties(int id = 0, int point = 0) {
		this->id = id;
		this->point = point;
	}

	bool operator>(const OlympiadProperties& other) const {
		if (point < other.point) return false;

		return point > other.point || id < other.id;
	}
};

class MergeSort {
public:
	OlympiadProperties* segmentStorage;

	void helperSort(OlympiadProperties*& arr, int l, int r) {
		if (l == r) return;

		int mid = (l + r) / 2;

		helperSort(arr, l, mid);
		helperSort(arr, mid + 1, r);

		mergeSegmentation(arr, l, r);
	}

	void sort(OlympiadProperties*& arr, int l, int r) {
		this->segmentStorage = new OlympiadProperties[r + 1];

		helperSort(arr, l, r);
	}

	void mergeSegmentation(OlympiadProperties*& arr, int l, int r) {
		int midBoundary = (l + r) / 2 + 1;
		int midInc = midBoundary;

		int leftInc = l;
		int pos = l;

		while (leftInc < midBoundary && midInc < r + 1) {
			if (arr[leftInc] > arr[midInc]) {
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

	scanf("%d\n", &n);

	OlympiadProperties* arr = new OlympiadProperties[n];

	for (int i = 0; i < n; i++) {
		arr[i].id = i + 1;
		scanf("%d", &arr[i].point);
	}

	MergeSort mS = MergeSort();
	mS.sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i].id);
}