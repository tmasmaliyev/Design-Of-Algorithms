#include <stdio.h>

int fibanocci(int x) {
    int prev = 1, curr = 1;

    for (int i = 2; i <= x; i++) {
        int tmp = curr;

        curr = curr + prev;
        prev = tmp;        
    }

    return curr;
}

int main() {
    int x;

    scanf("%d", &x);

    printf("%d", fibanocci(x));
}