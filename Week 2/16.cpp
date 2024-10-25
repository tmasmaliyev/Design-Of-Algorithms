#include <stdio.h>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>

int main() {
    int t, n, id, idValue, teamID, popTeam;
    std::string line, opCode;

    std::unordered_map<int, int> idToTeam;
    std::unordered_map<int, std::queue<int>> queueOrder;
    std::queue<int> teamOrder;

    scanf("%d\n", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d", &id);

            idToTeam[id] = i;
        }
    }

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);

        iss >> opCode;

        if (opCode == "ENQUEUE") {
            iss >> idValue;

            teamID = idToTeam[idValue];
            
            if (queueOrder[teamID].size() == 0)
                teamOrder.push(teamID);

            queueOrder[teamID].push(idValue);
        }
        else if (opCode == "DEQUEUE") {
            popTeam = teamOrder.front();

            printf("%d\n", queueOrder[popTeam].front());

            queueOrder[popTeam].pop();

            if (queueOrder[popTeam].size() == 0)
                teamOrder.pop();
        }
    }
}