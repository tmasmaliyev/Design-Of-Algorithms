#include <stdio.h>

int main() {
    int n, val, degreeByEdge;

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        degreeByEdge = 0;

        for (int j = 1; j <= n; j++) {
            scanf("%d ", &val);

            degreeByEdge+= val;
        }

        printf("%d\n", degreeByEdge);
    }
}