#include <stdio.h>
#include <deque>
#include <queue>

int main() {
    int n, k, val;
    std::deque<int> minQueue;
    std::queue<int> queue;

    scanf("%d %d\n", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);

        queue.push(val);

        while (!minQueue.empty() && minQueue.back() > val)
            minQueue.pop_back();
        
        minQueue.push_back(val);

        if (i >= k) {
            printf("%d ", minQueue.front());

            if (queue.front() == minQueue.front())
                minQueue.pop_front();
            
            queue.pop();
        }
    }
}