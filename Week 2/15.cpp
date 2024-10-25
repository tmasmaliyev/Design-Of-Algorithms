#include <stdio.h>
#include <queue>
#include <algorithm>

#define ll long long

int main() {
    int n, m, val;
    ll window = 0, maxWindow = 0;
    std::queue<int> q;

    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        q.push(val);
        window+= val;

        while (window > m) {
            window-= q.front();
            q.pop();
        }

        if (window <= m) 
            maxWindow = std::max(window, maxWindow);
    }
    printf("%lld", maxWindow);
}