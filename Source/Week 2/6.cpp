#include <iostream>
#include <stack>

int arr[10000];
int res[10000];

int main() {
    std::stack<int> s;

    int n;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s.empty()) {
            res[i] = -1;
            s.push(arr[i]);
        }
        else {
            while (!s.empty() && arr[i] >= s.top())
                s.pop();
            
            if (s.empty())
                res[i] = -1;
            else
                res[i] = s.top();

            s.push(arr[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
}