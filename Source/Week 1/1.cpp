#include <stdio.h>

int main() {
    int a, b;
    
    scanf_s("%d %d", &a, &b);

    printf("%d", (a + b) * (b - a + 1) / 2);
}