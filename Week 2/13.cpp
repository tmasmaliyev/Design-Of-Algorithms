#include <stdio.h>
#include <deque>
#include <queue>
#include <unordered_map>

#define ll long long

typedef std::pair<ll, ll> Pair;

const ll MOD = 1e6;


int main() {
    ll n, a, b, c, x, res = 0, tmp;

    std::unordered_map<int, int> container;
    std::queue<ll> queue;
    std::deque<ll> minQueue;

    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &x);

    for (ll i = 0; i < n; i++) {
        x = (a * x * x + b * x + c) / 100; 
        x = x % MOD;
        // printf("%lld\n", x);

        if (x % 5 < 2) {
            if (queue.empty())
                continue;

            tmp = queue.front();

            if (minQueue.front() == tmp)
                minQueue.pop_front();

            queue.pop();

            if (queue.empty())
                continue;
        }
        else {
            queue.push(x);
            
            while (!minQueue.empty() && minQueue.back() > x)
                minQueue.pop_back();
            
            minQueue.push_back(x);
        }
        res+= minQueue.front();
    }

    printf("%lld", res);
}