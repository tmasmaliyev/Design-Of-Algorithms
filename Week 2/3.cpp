#include <stdio.h>
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

typedef std::pair<int, int> Pair;

Pair popTwoAndGet(std::stack<int>& s) {
    int b = s.top();
    s.pop();

    int a = s.top();
    s.pop();

    return Pair(a, b);
}


int main() {
    std::stack<int> s;
    std::vector<std::string> operands;

    std::string line, ind_oper;
    std::getline(std::cin, line); 

    std::istringstream iss(line);

    while (iss >> ind_oper) {
        operands.push_back(ind_oper);
    }

    for (int i = 0; i < operands.size(); i++) {
        if (operands[i] == "*") {
            Pair p = popTwoAndGet(s);

            s.push(p.first * p.second);
        }
        else if (operands[i] == "+") {
            Pair p = popTwoAndGet(s);

            s.push(p.first + p.second);
        }
        else if (operands[i] == "-") {
            Pair p = popTwoAndGet(s);

            s.push(p.first - p.second);
        }
        else if (operands[i] == "/") {
            Pair p = popTwoAndGet(s);

            s.push(p.first / p.second);
        }
        else {
            s.push(std::stoi(operands[i]));
        }
    }
    printf("%d", s.top());
}