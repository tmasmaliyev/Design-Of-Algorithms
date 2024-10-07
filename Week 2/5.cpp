#include <iostream>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <string>


int main() {
    std::stack<int> s;
    std::string line;

    int n, opcode, pushVal;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);

        std::istringstream iss(line);

        iss >> opcode >> pushVal;

        if (opcode == 1) {
            if (!s.empty() && s.top() < pushVal)
                pushVal = s.top();
            
            s.push(pushVal);
        }
        else if (opcode == 2) {
            s.pop();
        }
        else if (opcode == 3) {
            printf("%d\n", s.top());
        }
    }
}