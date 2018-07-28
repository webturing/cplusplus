#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int hour, minute;
        char buf[200];

        int x, y = 0;
        scanf("%d %d %s", &hour, &minute, buf);
        if (strchr(buf, '.')) {
            sscanf(buf, "UTC%d.%d", &x, &y);
            if (strchr(buf, '-'))y *= -1;

        } else {
            sscanf(buf, "UTC%d", &x);
        }
        minute += y * 6;
        if (minute < 0) {
            minute += 60;
            --hour;
        }
        hour += x + minute / 60 + 16;
        hour %= 24;
        minute %= 60;
        printf("%02d:%02d\n", hour, minute);
    }

    return 0;
}
