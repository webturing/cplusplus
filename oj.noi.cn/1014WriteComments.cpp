#include <bits/stdc++.h>

using namespace std;

int main() {
    int score;
    cin >> score;
    if (score < 60) {
        cout << "Fail" << endl;
    } else if (score < 80) {
        cout << "Pass" << endl;
    } else if (score < 90) {
        cout << "Good" << endl;
    } else {
        cout << "Excellent" << endl;
    }
    return 0;
}