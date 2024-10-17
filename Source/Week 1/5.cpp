#include <stdio.h>
#include <unordered_map>

std::unordered_map<int, int> glob_vect;

int funFunction(int x, int y) {
    if (x <= 0 || y <= 0)
        return 0;

    int bitmask_val = (x << 6) | y;

    if (glob_vect.find(bitmask_val) != glob_vect.end())
        return glob_vect[bitmask_val];

    int val;

    if(x <= y) 
        val = funFunction(x - 1, y - 2) + funFunction(x - 2, y - 1) + 2;
    else if(x > y)
        val = funFunction(x - 2, y - 2) + 1;

    glob_vect[bitmask_val] = val;

    return glob_vect[bitmask_val];
}

int main() {
    int x, y;

    scanf("%d %d", &x, &y);

    printf("%d", funFunction(x, y));
}