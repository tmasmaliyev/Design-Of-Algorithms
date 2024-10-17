#include <stdio.h>
#include <stack>

typedef std::pair<int, int> Pair;
#define ll long long

const int MOD = 1e9 + 7;

int main() {
    std::stack<Pair> s;
    s.push({-1, -1});

    int i = 0, n, val, res = 0;
    ll tmpVal;

    scanf("%d\n", &n);

    for (; i < n; i++) {
        scanf("%d", &val);

        while (val < s.top().first) {
            Pair topVal = s.top();
            s.pop();

            tmpVal = topVal.first * (topVal.second - s.top().second) * (i - topVal.second); 

            res = (res + tmpVal) % MOD;
        }

        s.push({val, i});
    }

    while (!s.empty()) {
        Pair topVal = s.top();

        if (topVal.first == -1)
            break;

        s.pop();

        tmpVal = topVal.first * (topVal.second - s.top().second) * (i - topVal.second);
        res = (res + tmpVal) % MOD;
 
    }
    printf("%d", res);
}