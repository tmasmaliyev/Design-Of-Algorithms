#include <iostream>
#include <stdio.h>
#include <stack>

typedef std::pair<int, int> Pair;

int main() {
    std::stack<Pair> s;
    int n, val;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        if (s.empty()) {
            printf("%d ", -1);
            s.push({val, i});
        }
        else {
            while (!s.empty() && val >= s.top().first) 
                s.pop();
            
            if (s.empty()) 
                printf("%d ", -1);
            else
                printf("%d ", s.top().second);
            
            s.push({val, i});
        }
    }
}