#include <stdio.h>

int gcd(int x, int y) {
    if (x == 0)
        return y;

    if (x > y)
        return gcd(x % y, y);
    else if (x < y)
        return gcd(y % x, x);
}



int main() {
    int n, res, inp_val;

    scanf("%d", &n);
    scanf("%d", &res);

    for (int i = 1; i < n; i++) {
        scanf("%d", &inp_val);

        res = gcd(res, inp_val);
    }

    printf("%d", res);
}