#include <stdio.h>
#include <string>
#include <iostream>

int main() {
    std::string s;

    std::cin >> s;

    int caseVal = 0;
    bool flag = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            caseVal+= 1;
        }
        else if (s[i] == ')') {
            caseVal-= 1;
        }

        if (caseVal < 0) {
            flag = true;
            break;
        }
            
    }

    if (flag || caseVal != 0) {
        printf("NO");
    }
    else {
        printf("YES");
    }
}