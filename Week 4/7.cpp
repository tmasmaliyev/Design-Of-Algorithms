#include <stdio.h>
#include <algorithm>

#define ll long long

void heapify(ll *&heap, int i, int n) {

    ll maxValue = heap[i], tmp;
    int maxValueIndex = i;

    if (2 * i <= n && maxValue > heap[2 * i]) {
        maxValue = heap[2 * i];
        maxValueIndex = 2 * i;
    }

    if (2 * i + 1 <= n && maxValue > heap[2 * i + 1]) {
        maxValue = heap[2 * i + 1];
        maxValueIndex = 2 * i + 1;
    }

    if (maxValue != heap[i]) {
        tmp = heap[i];
        heap[i] = heap[maxValueIndex];
        heap[maxValueIndex] = tmp;

        heapify(heap, maxValueIndex, n);
    }
}

int main() {
    int n, k;
    ll ans = 0;

    scanf("%d %d\n", &n, &k);

    ll *queue = new ll[n + 1];
    ll *heap = new ll[k + 1];
    
    if (n <= k) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &queue[i]);
            ans = std::max(ans, queue[i]);
        }
    }
    else {
        for (int i = 1; i <= k; i++) {
            scanf("%d", &queue[i]);

            heap[i] = queue[i];
        }

        for (int j = k / 2; j >= 1; j--)
            heapify(heap, j, k);

        for (int i = k + 1; i <= n; i++) {
            scanf("%d", &queue[i]);

            heap[1]+= queue[i];

            heapify(heap, 1, k);
        }
        for (int i = 1; i <= k; i++)
            ans = std::max(ans, heap[i]);
    }
    printf("%lld\n", ans);
}