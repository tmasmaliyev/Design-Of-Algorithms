#include <stdio.h>
#include <iostream>

const int CUSTOMNUM = 1e7 + 1;

bool arr[CUSTOMNUM];

void sieve() {
    
    for (int i = 2; i * i <= CUSTOMNUM; i++) {
        if (!arr[i]) {
            for (int j = i * i; j <= CUSTOMNUM; j+=i) {
                arr[j] = true;
            }
        }
    }
}

int numOfPrimes(int a, int b) {
    int cnt = 0; 
    if (a == 1)
        a++;

    for (int i = a; i <= b; i++) {
        if (!arr[i])
            cnt+= 1;
    }

    return cnt;
}

int main() {
    int a, b;
    sieve();

    while (std::cin >> a >> b) {
        printf("%d\n\n", numOfPrimes(a, b));
    }
}