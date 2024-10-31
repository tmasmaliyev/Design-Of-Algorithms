#include <stdio.h>
#include <vector>

class CoordinateSystem{
public:
	int x, y;
	CoordinateSystem(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}

	bool operator>(const CoordinateSystem& other) const {
		int leftCoordinateSum = x + y;
		int rightCoordinateSum = other.x + other.y;

		if (leftCoordinateSum < rightCoordinateSum) return false;

		return leftCoordinateSum > rightCoordinateSum || x > other.x;
	}
	bool operator<(const CoordinateSystem& other) const {
		int leftCoordinateSum = x + y;
		int rightCoordinateSum = other.x + other.y;

		if (leftCoordinateSum > rightCoordinateSum) return false;

		return leftCoordinateSum < rightCoordinateSum || x < other.x;
	}
};

int partition(std::vector<CoordinateSystem>& arr, int l, int r) {
	int lp = l - 1;
	int rp = r + 1;
	CoordinateSystem piv = arr[l], tmp;

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

void quickSort(std::vector<CoordinateSystem>& arr, int l, int r) {
	if (l == r) return;

	int q = partition(arr, l, r);

	quickSort(arr, l, q);
	quickSort(arr, q + 1, r);
}

int main() {
	int x, y;
	std::vector<CoordinateSystem> arr;
	
	while (scanf("%d %d", &x, &y) == 2) 
		arr.push_back(CoordinateSystem(x, y));

	quickSort(arr, 0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
}