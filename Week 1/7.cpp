#include <stdio.h>

#define ll long long

ll modularExponentiation(ll x, ll n, ll m) {
    if (n == 0)
        return 1;

    ll prevVal;

    // Odd case
    if (n & 1) { 
        prevVal = modularExponentiation(x, n - 1, m);

        return (prevVal * x) % m;
    }
    // Even case
    else {
        prevVal = modularExponentiation(x, n / 2, m);

        return (prevVal * prevVal) % m;
    }

}

int main() {
    ll x, n, m;

    scanf("%lld %lld %lld", &x, &n, &m);

    x = x % m;

    printf("%lld", modularExponentiation(x, n, m));
}