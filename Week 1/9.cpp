#include <stdio.h>

#define ll long long

const int MOD = 1e9 + 7;

ll modularExponentiation(int x, int n) {
    if (n == 0)
        return 1;

    ll prevVal;

    // Odd case
    if (n & 1) {
        prevVal = modularExponentiation(x, n - 1);

        return (prevVal * x) % MOD; 
    }
    // Even case
    else {
        prevVal = modularExponentiation(x, n / 2);

        return (prevVal * prevVal) % MOD;
    }
}


int main() {
    ll n, k, res;

    scanf("%lld %lld", &n, &k);

    // Odd case
    if (n & 1) {
        res = modularExponentiation(k, (n + 1) / 2);

        res = (res * (n - 1)) % MOD;
    }
    // Even case
    else {
        res = modularExponentiation(k, n / 2);

        res = (n * k / 2 + (n / 2 - 1)) * res;

        res = res % MOD;
    }

    printf("%lld", res);
}