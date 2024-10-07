#include <stdio.h>

int main() {
    int n, val, degreeByEdge, hangingEdge = 0;

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        degreeByEdge = 0;

        for (int j = 1; j <= n; j++) {
            scanf("%d ", &val);

            degreeByEdge+= val;
        }
        if (degreeByEdge == 1)
            hangingEdge++;
    }    

    printf("%d\n", hangingEdge);
}