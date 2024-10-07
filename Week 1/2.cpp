#include <stdio.h>

bool checkPrime(int x) {
    
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
}

int main() {
    int x;

    scanf("%d", &x);

    if (checkPrime(x))
        printf("Yes");
    else
        printf("No");
}