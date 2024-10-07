#include <stdio.h>

const int CUSTOMMOD = 9929;

int extendedGCD(int a, int b, int* x, int* y) {

    if (b == 0) {
        *x = 1;
        *y = 0;

        return a;
    }
    int gcdVal = extendedGCD(b, a % b, x, y);

    int x_temp = *x;

    *x = *y;
    *y = x_temp - (a / b) * (*y);

    return gcdVal;
}


int combinatorics(int n, int k) {
    int res = 1; 
    int x, y;

    for (int i = 1; i <= k; i++) {
        res *= (n - i + 1);
        extendedGCD(CUSTOMMOD, i, &x, &y);

        if (y < 0)
            y+= CUSTOMMOD;

        res = ((res % CUSTOMMOD) * y) % CUSTOMMOD;
    }

    return res;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    printf("%d", combinatorics(n, k));
}