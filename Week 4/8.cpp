#include <stdio.h>
#include <queue>

bool isHeapOkay(std::priority_queue<int> &pq) {

    while (!pq.empty()) {
        int maxVal = pq.top(); pq.pop();

        std::queue<int> tempQueue;

        while (maxVal--) {
            if (pq.empty()) return false;
            if (pq.top() != 1) tempQueue.push(pq.top() - 1);

            pq.pop();
        } 

        while (!tempQueue.empty()) {
            pq.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    return true;
}

int main() {
    int val;
    char c;
    std::priority_queue<int> pq;

    while (scanf("%d%c", &val, &c) == 2) {
        pq.push(val);

        if (c == '\n') {
            printf(isHeapOkay(pq) ? "ok\n\n" : "fail\n\n");

            while (!pq.empty())
                pq.pop();
        }
    }
}