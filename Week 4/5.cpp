#include <stdio.h>

class TeamMember {
    public:
        int points;
        int member;

        TeamMember(int points = 0, int member = 0) : points(points), member(member) {}

    bool operator==(const TeamMember &other) const {
        return points == other.points;
    } 

    bool operator!=(const TeamMember &other) const {
        return !(*this == other);
    }

    bool operator<(const TeamMember &other) const {
        return points < other.points;
    }

    bool operator>(const TeamMember &other) const {
        return !(*this < other);
    }

    bool operator>=(const TeamMember &other) const {
        if (points == other.points) {
            if (member > other.member) return false;
            else return true;
        }

        return *this > other;
    }
};

void heapify(TeamMember *&allMembers, int i, int n) {

    TeamMember maxVal = allMembers[i], tmp;
    int maxValIndex = i;

    bool swapByMember = false;

    if (2 * i <= n && maxVal >= allMembers[2 * i]) {
        if (maxVal.points == allMembers[2 * i].points)
            swapByMember = true;
        else
            swapByMember = false;

        maxVal = allMembers[2 * i];
        maxValIndex = 2 * i;
    }

    if (2 * i + 1 <= n && maxVal >= allMembers[2 * i + 1]) {
        if (maxVal.points == allMembers[2 * i + 1].points)
            swapByMember = true;
        else
            swapByMember = false;

        maxVal = allMembers[2 * i + 1];
        maxValIndex = 2 * i + 1;
    }

    if (maxVal != allMembers[i] || swapByMember) {
        tmp = allMembers[i];
        allMembers[i] = maxVal;
        allMembers[maxValIndex] = tmp;

        heapify(allMembers, maxValIndex, n);
    }
}

int main() {
    int n, points, member;

    scanf("%d\n", &n);

    TeamMember *allMembers = new TeamMember[n + 1], tmp;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &points);

        allMembers[i] = TeamMember(points, i);
    }

    for (int inc = 0; inc < n; inc++) {
        for (int i = (n - inc) / 2; i >= 1; i--)
            heapify(allMembers, i, n - inc);
        
        // for (int i = 1; i <= n; i++)
        //     printf("%d ", allMembers[i].member);
        
        // printf("\n");
        tmp = allMembers[1];
        allMembers[1] = allMembers[n - inc];
        allMembers[n - inc] = tmp;

    }

    for (int i = 1; i <= n; i++)
        printf("%d ", allMembers[i].member);
}