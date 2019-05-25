#include<iostream>

using namespace std;

int main() {
    int temp;
    int score = 0;
    int lastScore = 0;
    cin >> temp;
    while (temp) {
        if (temp == 1) {
            score++;
            lastScore = 1;
        } else if (temp == 2) {
            if (lastScore == 1 || lastScore == 0) {
                score += 2;
                lastScore = 2;
            } else {
                lastScore += 2;
                score += lastScore;
            }
        }
        cin >> temp;
    }
    cout << score << endl;
    return 0;
}
