#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <sstream>

int main() {
    std::unordered_map<int, int> freqMap;
    std::string opCode, line;
    int pushVal, popElement, currFreq, maxFreq = 0;

    std::unordered_map<int, std::stack<int>> freqStack;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);

        iss >> opCode >> pushVal;

        if (opCode == "push") {
            freqMap[pushVal]++;
            currFreq = freqMap[pushVal];

            freqStack[currFreq].push(pushVal);
            maxFreq = std::max(maxFreq, currFreq);
                 
        }
        else if (opCode == "pop") {
            if (freqStack[maxFreq].empty())
                continue;

            popElement = freqStack[maxFreq].top();
            printf("%d\n", popElement);

            freqStack[maxFreq].pop();
            freqMap[popElement]--;

            if (freqStack[maxFreq].size() == 0) 
                maxFreq--;
        }
    }
}