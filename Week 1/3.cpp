#include <stdio.h>
#include <vector>

int main() {
    int x;

    std::vector<int> comb;

    scanf("%d", &x);

    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            comb.push_back(i);
            printf("%d ", i);
        }
    }

    for (int i = comb.size() - 1; i >= 0; i--) {
        if (comb[i] * comb[i] == x)
            continue;
        
        printf("%d ", x / comb[i]);
    }
}