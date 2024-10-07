#include <stdio.h>

int main() {
    int n, val;

    int roads = 0;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d ", &val);

            roads+= val;
        }
    }

    printf("%d\n", roads / 2);
}