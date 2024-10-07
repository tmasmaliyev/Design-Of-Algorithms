#include <stdio.h>

void heapify(int *arr, int i, int n, bool condition) {
    
    int valueOnCondition = arr[i], indexValue = i, tmp;

    if (2 * i <= n && ((condition && valueOnCondition < arr[2 * i]) || (!condition && valueOnCondition > arr[2 * i])) ) {
        valueOnCondition = arr[2 * i];
        indexValue = 2 * i;
    }

    if (2 * i + 1<= n && ((condition && valueOnCondition < arr[2 * i + 1]) || (!condition && valueOnCondition > arr[2 * i + 1]))) {
        valueOnCondition = arr[2 * i + 1];
        indexValue = 2 * i + 1;
    }

    if (valueOnCondition != arr[i]) {
        tmp = arr[i];
        arr[i] = valueOnCondition;
        arr[indexValue] = tmp;

        heapify(arr, indexValue, n, condition);
    }
}

int main() {
    int n, oddsCount = 0, evenCount = 0, val, tmp;

    scanf("%d\n", &n);

    int *odds = new int[n + 1];
    int *evens = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);

        if (val % 2 == 0) {
            evens[evenCount + 1] = val;
            evenCount++;
        }
        else {
            odds[oddsCount + 1] = val;
            oddsCount++;
        }
    }

    for (int inc = 0; inc < oddsCount; inc++) {
        for (int i = (oddsCount - inc) / 2; i >= 1; i--) 
            heapify(odds, i, oddsCount - inc, true);

        tmp = odds[1];
        odds[1] = odds[oddsCount - inc];
        odds[oddsCount - inc] = tmp;
    }

    // for (int i = 1; i <= oddsCount; i++)
    //     printf("%d ", odds[i]);
    

    for (int inc = 0; inc < evenCount; inc++) {
        for (int i = (evenCount - inc) / 2; i >= 1; i--)
            heapify(evens, i, evenCount - inc, false);

        tmp = evens[1];
        evens[1] = evens[evenCount - inc];
        evens[evenCount - inc] = tmp;
    } 

    for (int i = 1; i <= oddsCount; i++)
        printf("%d ", odds[i]);
        
    for (int i = 1; i <= evenCount; i++)
        printf("%d ", evens[i]);
}