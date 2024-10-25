#include <stdio.h>
#include <algorithm>

class RoadStructure {
public:
	int dangerLevel;
	int edge1;
	int edge2;

	RoadStructure(int dangerLevel = 0, int edge1 = 0, int edge2 = 0) {
		this->dangerLevel = dangerLevel;
		this->edge1 = edge1;
		this->edge2 = edge2;
	}

	bool operator<(const RoadStructure &other) const {
		return this->dangerLevel < other.dangerLevel;
	}
	bool operator!=(const RoadStructure& other) const {
		return this->dangerLevel != other.dangerLevel;
	}
};

void heapify(RoadStructure*& roads, int i, int m) {
	RoadStructure temp;
	int minValueIndex = i;

	if (2 * i <= m && roads[minValueIndex] < roads[2 * i]) {
		minValueIndex = 2 * i;
	}

	if (2 * i + 1 <= m && roads[minValueIndex] < roads[2 * i + 1]) {
		minValueIndex = 2 * i + 1;
	}

	if (i != minValueIndex) {
		temp = roads[i];
		roads[i] = roads[minValueIndex];
		roads[minValueIndex] = temp;

		heapify(roads, minValueIndex, m);
	}
}

void heapSort(RoadStructure*& roads, int m) {
	
	RoadStructure temp;

	for (int i = m / 2; i > 0; i--) 
		heapify(roads, i, m);

	for (int i = m; i > 0; i--) {
		heapify(roads, 1, i);

		temp = roads[1];
		roads[1] = roads[i];
		roads[i] = temp;
	}
}

int Repr(int x, int*& dsu) {
	
	if (dsu[x] == x) return x;

	return dsu[x] = Repr(dsu[x], dsu);
}

void makeUnion(int x, int y, int*& dsu, int*& rank) {
	int reprX = Repr(x, dsu);
	int reprY = Repr(y, dsu);

	if (reprX == reprY) return;
	else {
		if (rank[reprX] > rank[reprY]) {
			dsu[reprY] = reprX;
		}
		else if (rank[reprX] < rank[reprY]) {
			dsu[reprX] = reprY;
		}
		else if (rank[reprX] == rank[reprY]) {
			dsu[reprX] = reprY;
			rank[reprY]++;
		}
	}
}

int main() {
	int n, m;

	scanf_s("%d %d", &n, &m);
	
	RoadStructure *roads = new RoadStructure[m + 1];

	for (int i = 1; i <= m; i++) {
		scanf_s("%d %d %d", &roads[i].edge1, &roads[i].edge2, &roads[i].dangerLevel);
	}
	
	heapSort(roads, m);

	int* dsu = new int[n + 1];
	int* rank = new int[n + 1];
	int maxDangerousValue = 0;

	for (int i = 1; i <= n; i++) {
		dsu[i] = i;
		rank[i] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int reprX = Repr(1, dsu);
		int reprY = Repr(n, dsu);

		if (reprX == reprY) break;
		else {
			makeUnion(roads[i].edge1, roads[i].edge2, dsu, rank);

			maxDangerousValue = roads[i].dangerLevel;
		}
	}
	
	printf("%d", maxDangerousValue);
}