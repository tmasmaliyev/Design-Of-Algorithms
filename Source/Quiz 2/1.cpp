#include <stdio.h>
#include <iostream>
#include <string>


class ACMProperties {
public:
	std::string teamName;
	int solved;
	int penalty;
	int id;

	ACMProperties(std::string teamName = "", int solved = 0, int penalty = 0) {
		this->teamName = teamName;
		this->solved = solved;
		this->penalty = penalty;
	}

	bool operator>(const ACMProperties& other) const {
		if (solved < other.solved) return false;
		else if (solved > other.solved) return true;

		if (penalty > other.penalty) return false;
		else if (penalty < other.penalty) return true;
		
		if (id > other.id) return false;
		else if (id < other.id) return true;
	}

};

void heapify(ACMProperties*& arr, int i, int n) {
	ACMProperties maxVal = arr[i], tmp;
	int maxValIndex = i;

	if (2 * i <= n && maxVal > arr[2 * i]) {
		maxVal = arr[2 * i];
		maxValIndex = 2 * i;
	}

	if (2 * i + 1 <= n && maxVal > arr[2 * i + 1]) {
		maxVal = arr[2 * i + 1];
		maxValIndex = 2 * i + 1;
	}

	if (maxValIndex != i) {
		tmp = arr[i];
		arr[i] = maxVal;

		arr[maxValIndex] = tmp;

		heapify(arr, maxValIndex, n);
	}
}

void heapSort(ACMProperties*& arr, int n) {
	ACMProperties tmp;

	for (int inc = 0; inc < n; inc++) {
		for (int i = (n - inc) / 2; i >= 1; i--)
			heapify(arr, i, n - inc);

		tmp = arr[1];
		arr[1] = arr[n - inc];
		arr[n - inc] = tmp;
	}
}

int main() {
	int n;

	scanf("%d", &n);

	ACMProperties* arr = new ACMProperties[n + 1];

	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i].teamName;
		
		scanf("%d %d", &arr[i].solved, &arr[i].penalty);
		arr[i].id = i;
	}

	heapSort(arr, n);

	for (int i = 1; i <= n; i++)
		std::cout << arr[i].teamName << " " << arr[i].solved << " " << arr[i].penalty << std::endl;
}