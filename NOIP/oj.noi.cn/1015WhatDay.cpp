#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<string> week(8);
    week[1] = "Monday";
    week[2] = "Tuesday";
    week[3] = "Wednesday";
    week[4] = "Thursday";
    week[5] = "Friday";
    week[6] = "Saturday";
    week[7] = "Sunday";
    int d;
    cin >> d;
    cout << week[d] << endl;

    return 0;
}
