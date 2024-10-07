#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>


int main() {
    std::stack<int> s;
    std::string line;

    std::string command;
    int n;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);

        iss >> command >> n;

        if (command == "push") {
            s.push(n);
            printf("ok\n");
        }
        else if (command == "pop") {
            printf("%d\n", s.top());
            s.pop();
        }
        else if (command == "back") {
            printf("%d\n", s.top());
        }
        else if (command == "size") {
            printf("%d\n", s.size());
        }
        else if (command == "clear") {
            while (!s.empty()) {
                s.pop();
            }
            printf("ok\n");
        }
        else if (command == "exit") {
            printf("bye\n");
            break;
        }
    }
}