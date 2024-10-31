#include <stdio.h>

class OlympiadProperties {
public:
	int id, points;
	OlympiadProperties(int id = 0, int points = 0) {
		this->id = id;
		this->points = points;
	}

	bool operator>(const OlympiadProperties& other) const {
		if (points < other.points) return false;
		
		return points > other.points || id < other.id;
	}
	bool operator<(const OlympiadProperties& other) const {
		if (points > other.points) return false;

		return points < other.points || id > other.id;
	}
};

int partition(OlympiadProperties*& arr, int l, int r) {
	int lp = l - 1;
	int rp = r + 1;
	OlympiadProperties piv = arr[l], tmp;

	while (1) {
		do rp--; while (arr[rp] < piv);
		do lp++; while (arr[lp] > piv);

		if (lp < rp) {
			tmp = arr[lp];
			arr[lp] = arr[rp];
			arr[rp] = tmp;
		}
		else return rp;
	}
}

void quickSort(OlympiadProperties*& arr, int l, int r) {
	if (l == r) return;

	int q = partition(arr, l, r);

	quickSort(arr, l, q);
	quickSort(arr, q + 1, r);
}

int main() {
	int n;

	scanf("%d", &n);
	OlympiadProperties* arr = new OlympiadProperties[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].points);

		arr[i].id = i + 1;
	}

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i].id);
}