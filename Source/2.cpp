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

	bool operator>(const TimeProperties& other) const {
		if (hour < other.hour) return false;
		else if (hour > other.hour) return true;
		
		if (minute < other.minute) return false;
		else if (minute > other.minute) return true;

		return second > other.second;
	}

	bool operator<(const TimeProperties& other) const {
		if (hour > other.hour) return false;
		else if (hour < other.hour) return true;

		if (minute > other.minute) return false;
		else if (minute < other.minute) return true;

		return second < other.second;
	}
};

int partition(TimeProperties *&arr, int l, int r) {
	int i = l - 1, j = r + 1;
	TimeProperties piv = arr[l], temp;

	while (1) {
		do j--; while (arr[j] > piv);
		do i++; while (arr[i] < piv);

		if (i < j) {
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		else return j;
	}
}

void quickSort(TimeProperties *&arr, int l, int r) {
	if (l == r) return;

	int q = partition(arr, l, r);
	
	quickSort(arr, l, q);
	quickSort(arr, q + 1, r);
}

int main() {
	int n;

	scanf("%d", &n);

	TimeProperties* arr = new TimeProperties[n];

	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &arr[i].hour, &arr[i].minute, &arr[i].second);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", arr[i].hour, arr[i].minute, arr[i].second);
}