#include <string>
#include <stdio.h>
#include <iostream>

int main() {
    int res = 0, count = 1, n;
    int arr[100];

    scanf("%d", &n);

    scanf("%d", &arr[0]);
    res = arr[0];

    for (int i = 1; i < n; i++) {
        scanf("%d", &arr[i]);

        if (res == arr[i])
            count++;
        else {
            count--;

            if (count < 0)
                res = arr[i], count = 1;
        }
            
    }

    int confirmCount = 0;

    for (int i = 0; i < n; i++) {
        if (res == arr[i])
            confirmCount++;
    }
    }

    if (confirmCount > n / 2)
        printf("%d", res);
    else
        printf("%d", -1);
}