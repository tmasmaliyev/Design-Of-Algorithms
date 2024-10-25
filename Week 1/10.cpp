#include <stdio.h>
#include <map>

std::map<std::pair<int, int>, int> lookup;
const int CUSTOMMOD = 9929;

int combinatorics(int n, int k) {

    if (k == 0 || n == k)
        return 1;

    if (lookup.find({n, k}) != lookup.end() ) {
        return lookup[{n, k}];
    }

    lookup[{n, k}] = (combinatorics(n - 1, k) + combinatorics(n - 1, k - 1)) % CUSTOMMOD;

    return lookup[{n, k}];
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    printf("%d", combinatorics(n, k));
}