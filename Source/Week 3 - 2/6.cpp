#include <stdio.h>

int main() {
    int n, val, diagSum = 0;

    scanf("%d\n", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d ", &val);

            if (i == j && val == 1)
                diagSum++;
        }
    }

    if (diagSum == 0)
        printf("NO");
    else
        printf("YES");
}