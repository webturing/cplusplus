//
// Created by jal on 18-7-14.
//

#include <bits/stdc++.h>

using namespace std;

int up = 1, to = 3, face = 2;
long long sum = 1LL;

void turn_left_right() {
    int t = up;
    up = 7 - to;
    to = t;
    sum += up;
}

void turn_up_down() {
    int t = face;
    face = up;
    up = 7 - t;
    to = 7 - to;
    sum += up;
}

int main() {
    ifstream cin("input.txt");
    long long r, c;
    cin >> r >> c;
    if (c - 1 >= 4) {
        sum += ((c - 1) / 4) * r * 14;
        c -= 4 * ((c - 1) / 4);
    }
    for (int i = 1; i <= r; i++) {
        if (i & 1) {
            if (i != 1) {
                turn_up_down();
            }
            for (int i = 1; i < c; i++) {
                turn_left_right();
            }
        } else {
            turn_up_down();
            for (int i = c; i > 1; i--) {
                turn_left_right();
            }
        }
    }
    cout << sum << endl;
}