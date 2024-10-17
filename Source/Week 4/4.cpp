#include <stdio.h>

class TimeProperties {
    public:
        int hour;
        int minutes;
        int seconds;
    
    bool operator==(const TimeProperties &other) const {
        return (hour == other.hour && 
                minutes == other.minutes &&
                seconds == other.seconds);
    }
    bool operator<(const TimeProperties &other) const {
        if (hour < other.hour) return true;
        if (hour > other.hour) return false;

        if (minutes < other.minutes) return true;
        if (minutes > other.minutes) return false;

        return seconds < other.seconds;
    }

    bool operator!=(const TimeProperties &other) const {
        return !(*this == other);
    }
};

void heapify(TimeProperties *&arr, int i, int n) {

    TimeProperties maxVal = arr[i], tmp;

    int maxValIndex = i;

    if (2 * i <= n && maxVal < arr[2 * i]) {
        maxVal = arr[2 * i];
        maxValIndex = 2 * i;
    }

    if (2 * i + 1 <= n && maxVal < arr[2 * i + 1]) {
        maxVal = arr[2 * i + 1];
        maxValIndex = 2 * i + 1;
    }

    if (maxVal != arr[i]) {
        tmp = arr[i];
        arr[i] = maxVal;
        arr[maxValIndex] = tmp;

        heapify(arr, maxValIndex, n);
    }
}

int main() {
    int n;
    int hour, minutes, seconds;

    scanf("%d\n", &n);

    TimeProperties *arr = new TimeProperties[n + 1], tmp;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &hour, &minutes, &seconds);

        arr[i] = TimeProperties 
        {
            hour = hour, 
            minutes = minutes,
            seconds = seconds
        };
    }

    for (int inc = 0; inc < n; inc++) {
        for (int i = (n - inc) / 2; i >= 1; i--) 
            heapify(arr, i, n - inc);
        
        tmp = arr[1];
        arr[1] = arr[n - inc];
        arr[n - inc] = tmp;
    }

    for (int i = 1; i <= n; i++)
        printf("%d %d %d\n", arr[i].hour, arr[i].minutes, arr[i].seconds);
}