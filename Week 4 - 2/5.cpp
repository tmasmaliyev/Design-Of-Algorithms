#include <stdio.h>
#include <utility>
#include <cstring>

int Repr(int x, int*& dsu) {

	if (x == dsu[x]) return x;

	return dsu[x] = Repr(dsu[x], dsu);
}

void makeUnion(int x, int y, int *&dsu, int *&rank) {

	int reprX = Repr(x, dsu);
	int reprY = Repr(y, dsu);

	if (reprX == reprY) return;
	else {
		if (dsu[reprX] > dsu[reprY]) {
			dsu[reprY] = reprX;
		}
		else if (dsu[reprX] < dsu[reprY]) {
			dsu[reprX] = reprY;
		}
		else if (dsu[reprX] == dsu[reprY]) {
			dsu[reprX] = reprY;
			rank[reprY]++;
		}
	}
}

int main() {
	int v, e, k;
	int tempX, tempY;

	scanf_s("%d %d %d", &v, &e, &k);

	int* dsu = new int[v + 1];
	int* rank = new int[v + 1];

	for (int i = 1; i <= v; i++) {
		dsu[i] = i;
		rank[i] = 1;
	}
	
	int* operations = new int[k];
	std::pair<int, int>* operationsCode = new std::pair<int, int>[k];

	int askCount = 0;

	char* text = new char[4];

	for (int i = 0; i < e; i++) {
		scanf_s("%d %d", &tempX, &tempY);
	}

	for (int i = 0; i < k; i++) {
		scanf_s("%s", text, 4);
		scanf_s("%d %d", &operationsCode[i].first, &operationsCode[i].second);

		// If `ask`, then return 0
		// If `cut`, then return 1

		if (strcmp(text, "ask") == 0) {
			operations[i] = 0;
			askCount++;
		}
		else if (strcmp(text, "cut") == 0) operations[i] = 1;
	}

	int* askCodes = new int[askCount];
	int askCodeIndex = askCount - 1;

	for (int i = k - 1; i >= 0; i--) {
		if (operations[i] == 0) { // Ask
			int reprX = Repr(operationsCode[i].first, dsu);
			int reprY = Repr(operationsCode[i].second, dsu);
					
			// Yes , 1
			// No, 0

			if (reprX == reprY) askCodes[askCodeIndex] = 1;
			else askCodes[askCodeIndex] = 0;

			askCodeIndex--;
		}
		else if (operations[i] == 1) { // Cut & (JOIN)
			makeUnion(
				operationsCode[i].first,
				operationsCode[i].second,
				dsu,
				rank
			);
		}
	}

	for (int i = 0; i < askCount; i++) {
		if (askCodes[i] == 1)
			printf("YES\n");
		else if (askCodes[i] == 0)
			printf("NO\n");
	}
}