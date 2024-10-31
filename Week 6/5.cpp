#include <stdio.h>

class Integer {
private:
	int number;
	bool OddOrEven;

public:
	int getInteger() {
		return this->number;
	}

	bool IsOddorEven() {
		return this->OddOrEven;
	}

	void setInteger(int number) {
		this->number = number;

		if (this->number % 2 == 0)
			this->OddOrEven = false;
		else
			this->OddOrEven = true;
	}

	Integer(int number = 0) {
		this->number = number;

		if (number % 2 == 0) this->OddOrEven = false;
		else this->OddOrEven = true;
	}

	bool operator>(const Integer& other) const {

		if (OddOrEven > other.OddOrEven) return false;
		if (OddOrEven < other.OddOrEven) return true;

		if (OddOrEven == 1) return number > other.number;

		return number < other.number;
	}
	bool operator<(const Integer& other) const {
		if (OddOrEven < other.OddOrEven) return false;
		if (OddOrEven > other.OddOrEven) return true;

		if (OddOrEven == 1) return number < other.number;

		return number > other.number;
	}
};

int partition(Integer*& arr, int l, int r) {
	int lp = l - 1;
	int rp = r + 1;

	Integer piv = arr[l], tmp;

	while (1) {
		do rp--; while (arr[rp] > piv);
		do lp++; while (arr[lp] < piv);

		if (lp < rp) {
			tmp = arr[lp];
			arr[lp] = arr[rp];
			arr[rp] = tmp;
		}
		else return rp;
	}
}

void quickSort(Integer*& arr, int l, int r) {
	if (l == r) return;

	int q = partition(arr, l, r);

	quickSort(arr, l, q);
	quickSort(arr, q + 1, r);
}

int main() {
	int n, val;

	scanf("%d", &n);

	Integer* arr = new Integer[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &val);

		arr[i].setInteger(val);
	}

	quickSort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i].getInteger());
}