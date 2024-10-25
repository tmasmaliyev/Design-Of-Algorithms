#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class DatetimeProperties{
public:
	int day;
	int month;
	int year;
	DatetimeProperties(int day = 0, int month = 0, int year = 0) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	bool operator<(const DatetimeProperties& other) const {
		if (year > other.year) return false;
		else if (year < other.year) return true;

		if (month > other.month) return false;
		else if (month < other.month) return true;

		if (day > other.day) return false;
		else if (day < other.day) return true;

		return false;
	}

	bool operator>(const DatetimeProperties& other) const {
		if (year < other.year) return false;
		else if (year > other.year) return true;

		if (month < other.month) return false;
		else if (month > other.month) return true;

		if (day < other.day) return false;
		else if (day > other.day) return true;
		
		return false;
	}
};


int partition(DatetimeProperties*& arr, int l, int r) {

	DatetimeProperties piv = arr[l], temp;
	int i = l - 1, j = r + 1;

	while (1) {
		do j--; while (arr[j] > piv);
		do i++; while (arr[i] < piv);

		if (i < j)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		else return j;
	}
}

void quickSort(DatetimeProperties*& arr, int l, int r) {

	if (l == r) return;

	int q = partition(arr, l, r);

	quickSort(arr, l, q);
	quickSort(arr, q + 1, r);
}

int main() {
	int n;
	std::string tmp, seg;

	std::cin >> n;
	DatetimeProperties* arr = new DatetimeProperties[n];

	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		std::istringstream iss(tmp);
		std::vector<int> testVector;

		while (std::getline(iss, seg, '.')) {
			testVector.push_back(stoi(seg));
		}

		arr[i].day = testVector[0];
		arr[i].month = testVector[1];
		arr[i].year = testVector[2];
	}
	
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i].day << "." << arr[i].month << "." << arr[i].year << std::endl;
	}
}