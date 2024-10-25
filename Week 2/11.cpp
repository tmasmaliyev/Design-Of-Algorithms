#include <stdio.h>
#include <stack>

#define ll long long

typedef std::pair<int, int> Pair;

int main() {
    Pair popValue;

    std::stack<Pair> s;
    int n, val;
    ll res = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        while (!s.empty() && val > s.top().first)
            s.pop();

        if (s.empty() || (!s.empty() &&s.top().first != val))
            s.push({val, 1});
        else {
            popValue = s.top();
            s.pop();

            res+= popValue.second;

            popValue.second++;

            s.push(popValue);    
        }
        
    }
    printf("%lld", res);
}