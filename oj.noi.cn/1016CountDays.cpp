#include <bits/stdc++.h>

using namespace std;

inline bool leap(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int main(int argc, char const *argv[]) {
    int daysOfMonth[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    int year, month;
    cin >> year >> month;
    cout << daysOfMonth[leap(year)][month] << endl;
    return 0;
}
