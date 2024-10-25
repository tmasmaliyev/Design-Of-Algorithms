#include <stdio.h>

bool arr[100001];

void sieve(int a, int b) {
    
    for (int i = 2; i * i <= b; i++) {
        if (!arr[i]) {
            for (int j = i * i; j <= b; j+=i) {
                arr[j] = true;
            }
        }
    }

    if (a == 1)
        a+= 1;

    for (int i = a; i <= b; i++) {
        if (!arr[i])
            printf("%d ", i);
    }
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    sieve(a, b);
}