#include <stdio.h>
#include <iostream>

#include <sstream>
#include <string>

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
	int n;

	while (std::cin >> n) {
		int edge1, edge2;
		int yesAns = 0, noAns = 0;

		std::string opText, opCode;
		const int MAXSIZE = 1e6;

		int maxId = n + 1;
		int* dsu = new int[MAXSIZE + 1];
		int* rank = new int[MAXSIZE + 1];
		int* ids = new int[MAXSIZE + 1];

		for (int i = 1; i <= MAXSIZE; i++) {
			dsu[i] = i;
			rank[i] = 1;
			ids[i] = i;
		}
		while (std::getline(std::cin, opText)) {
			std::istringstream iss(opText);

			iss >> opCode;

			if (opCode == "c") {
				iss >> edge1 >> edge2;
				makeUnion(ids[edge1], ids[edge2], dsu, rank);
			}
			else if (opCode == "q") {
				iss >> edge1 >> edge2;

				int reprX = Repr(ids[edge1], dsu);
				int reprY = Repr(ids[edge2], dsu);

				if (reprX == reprY) yesAns++;
				else noAns++;
			}
			else if (opCode == "d") {
				iss >> edge1;

				ids[edge1] = maxId;
				maxId++;
			}
			else if (opCode == "e") {
				break;
			}
		}

		printf("%d , %d\n", yesAns, noAns);
	}
}