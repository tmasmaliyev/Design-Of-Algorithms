#include <stdio.h>
#include <deque>

int main() {
    int n, instruction, val;
    std::deque<int> queue;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("\n%d ", &instruction);

        if (instruction == 1 || instruction == 2) {
            scanf(" %d", &val);

            if (instruction == 1) 
                queue.push_front(val);
            else if (instruction == 2)
                queue.push_back(val);

        }
        else if (instruction == 3) {
            printf("%d\n", queue.front());
            queue.pop_front();
        }
        else if (instruction == 4) {
            printf("%d\n", queue.back());
            queue.pop_back();
        }
    }
}