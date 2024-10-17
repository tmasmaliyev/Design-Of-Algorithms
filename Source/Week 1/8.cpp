#include <stdio.h>

#define ll long long

const int MOD = 1e9 + 7;

ll modularExponentiation(ll x, ll n) {
    if (n == 0)
        return 1;

    ll prevVal;

    // Odd case
    if (n & 1) {
        prevVal = modularExponentiation(x, n - 1);

        return (x * prevVal) % MOD;
    }
    // Even case
    else {
        prevVal = modularExponentiation(x, n / 2);

        return (prevVal * prevVal) % MOD;
    }
}


int main() {
    ll n;

    scanf("%lld", &n);

    ll res = n * modularExponentiation(n - 1, n - 1);

    printf("%lld", res % MOD);

}