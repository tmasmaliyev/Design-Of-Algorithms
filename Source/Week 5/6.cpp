#include <stdio.h>

class TimeProperties {
public:
	int hour;
	int minute;
	int second;

	TimeProperties(int hour = 0, int minute = 0, int second = 0) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	bool operator<(const TimeProperties& other) const {
		bool total_cond = true;

		if (hour > other.hour) return false;
		if (hour < other.hour) return true;

		if (minute > other.minute) return false;
		if (minute < other.minute) return true;

		return second < other.second;
	}
};

class MergeSort {
public:
	TimeProperties* segmentStorage;

	void helperSort(TimeProperties*& arr, int l, int r) {
		if (l == r) return;

		int mid = (l + r) / 2;

		helperSort(arr, l, mid);
		helperSort(arr, mid + 1, r);

		mergeSegmentation(arr, l, r);
	}

	void sort(TimeProperties*& arr, int l, int r) {
		this->segmentStorage = new TimeProperties[r + 1];

		helperSort(arr, l, r);
	}

	void mergeSegmentation(TimeProperties*& arr, int l, int r) {
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

	TimeProperties* arr = new TimeProperties[n];

	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &arr[i].hour, &arr[i].minute, &arr[i].second);

	MergeSort mS = MergeSort();
	mS.sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", arr[i].hour, arr[i].minute, arr[i].second);
}