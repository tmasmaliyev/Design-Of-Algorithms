#include <stdio.h>
#include <string>
#include <iostream>

class PeopleProperties {
public:
	std::string name;
	std::string surname;
	int yearOfBirth;
	PeopleProperties(std::string name = "", std::string surname = "", int yearOfBirth = 0) {
		this->name = name;
		this->surname = surname;
		this->yearOfBirth = yearOfBirth;
	}

	bool operator<(const PeopleProperties& other) const {
		if (surname > other.surname) return false;
		else if (surname < other.surname) return true;

		if (name > other.name) return false;
		else if (name < other.name) return true;

		if (yearOfBirth < other.yearOfBirth) return false;
		else if (yearOfBirth > other.yearOfBirth) return true;
	}
};


class MergeSort {
public:
	PeopleProperties* segmentStorage;

	void helperSort(PeopleProperties* arr, int l, int r) {
		if (l == r) return;

		int mid = (l + r) / 2;

		helperSort(arr, l, mid);
		helperSort(arr, mid + 1, r);

		mergeSegmentation(arr, l, r);
	}

	void sort(PeopleProperties* arr, int l, int r) {
		this->segmentStorage = new PeopleProperties[r + 1];

		helperSort(arr, l, r);
	}

	void mergeSegmentation(PeopleProperties* arr, int l, int r) {
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

	PeopleProperties* arr = new PeopleProperties[n];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i].name >> arr[i].surname >> arr[i].yearOfBirth;
	}
	
	MergeSort mS = MergeSort();
	mS.sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		std::cout << arr[i].name << " " << arr[i].surname << " " << arr[i].yearOfBirth << std::endl;
}