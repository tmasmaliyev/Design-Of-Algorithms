#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

class DisjointUnionSet {
public:
	int* dsu;
	int* rank;
	int* minInSet;
	int* maxInSet;
	int* elementCount;

	DisjointUnionSet(int length) {
		this->dsu = new int[length + 1];
		this->rank = new int[length + 1];
		this->minInSet = new int[length + 1];
		this->maxInSet = new int[length + 1];
		this->elementCount = new int[length + 1];

		for (int i = 1; i <= length; i++) {
			this->dsu[i] = i;
			this->rank[i] = 1;

			this->minInSet[i] = i;
			this->maxInSet[i] = i;
	
			this->elementCount[i] = 1;
		}
	}
	int Repr(int x) {
		if (this->dsu[x] == x) return x;

		return this->dsu[x] = this->Repr(this->dsu[x]);
	}
	void makeUnion(int x, int y) {
		int reprX = this->Repr(x);
		int reprY = this->Repr(y);

		if (reprX == reprY) return;
		else {
			if (this->rank[reprX] > this->rank[reprY]) {
				this->dsu[reprY] = reprX;

				this->minInSet[reprX] = std::min(this->minInSet[reprX], this->minInSet[reprY]);
				this->maxInSet[reprX] = std::max(this->maxInSet[reprX], this->maxInSet[reprY]);

				this->elementCount[reprX] += this->elementCount[reprY];
			}
			else if (this->rank[reprX] < this->rank[reprY]) {
				this->dsu[reprX] = reprY;

				this->minInSet[reprY] = std::min(this->minInSet[reprX], this->minInSet[reprY]);
				this->maxInSet[reprY] = std::max(this->maxInSet[reprX], this->maxInSet[reprY]);

				this->elementCount[reprY] += this->elementCount[reprX];
			}
			else if (this->rank[reprX] == this->rank[reprY]) {
				this->dsu[reprX] = reprY;
				this->rank[reprY]++;

				this->minInSet[reprY] = std::min(this->minInSet[reprX], this->minInSet[reprY]);
				this->maxInSet[reprY] = std::max(this->maxInSet[reprX], this->maxInSet[reprY]);

				this->elementCount[reprY] += this->elementCount[reprX];
			}
		}
	}
};

int main() {
	int n, m;
	int edge1, edge2, getVal;

	std::string text;
	std::string op;

	scanf_s("%d %d\n", &n, &m);

	DisjointUnionSet unionSet = DisjointUnionSet(n);

	for (int i = 1; i <= m; i++) {
		std::getline(std::cin, text);

		std::istringstream iss(text);

		iss >> op;

		if (op == "union") {
			iss >> edge1 >> edge2;

			unionSet.makeUnion(edge1, edge2);
		}
		else if (op == "get") {
			iss >> getVal;

			int repr = unionSet.Repr(getVal);

			printf("%d %d %d\n", unionSet.minInSet[repr], unionSet.maxInSet[repr], unionSet.elementCount[repr]);
		}
	}
}