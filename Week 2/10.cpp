#include <stdio.h>
#include <iostream>
#include <stack>

#define ll long long

typedef std::pair<ll, ll> Pair;

int main() {
    ll n, val, i = 0;
    ll res = 0, temp;

    Pair popValue;
    std::stack<Pair> s;
    
    s.push({-1, -1});

    scanf("%lld", &n);

    for (; i < n; i++) {
        scanf("%d", &val);
        res = std::max(res, (ll)val);

        while (val < s.top().second) {
            popValue = s.top();
            s.pop();

            temp = popValue.second * (i - s.top().first - 1);

            res = std::max(res, temp);
        }
        s.push({i, val});
    }        

    while (s.top().first != -1) {
        popValue = s.top();
        s.pop();

        temp = popValue.second * (i - s.top().first - 1);
        res = std::max(res, temp);
    }

    printf("%lld", res);
}