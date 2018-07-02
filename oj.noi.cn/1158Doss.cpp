#include <bits/stdc++.h>

using namespace std;

struct Doss {
    int up, down, left, right, front, back;

    Doss() { up = 1, down = 6, left = 4, right = 3, front = 2, back = 5; }

    void moveLeftToRight() {
        int up, down, left, right, front, back;
        up = this->left, down = this->right, right = this->up, left = this->down;
        this->up = up, this->down = down, this->right = right, this->left = left;
    }

    void moveRightToLeft() {
        int up, down, left, right, front, back;
        up = this->right, down = this->left, left = this->up, right = this->down;
        this->up = up, this->down = down, this->right = right, this->left = left;
    }

    void moveUpToDown() {
        int up, down, left, right, front, back;
        down = this->front, front = this->up, up = this->back, back = this->down;
        this->down = down, this->front = front, this->up = up, this->back = back;
    }
};

int main() {
    int r, c;
    cin >> r >> c;
    Doss doss;
    long long up = doss.up;
    for (int i = 0; i < r; i++) {
        up += (c - 1) / 4 * 14;
        if (i & 1)
            for (int j = 0; j < (c - 1) % 4; j++)doss.moveRightToLeft(), up += doss.up;
        else
            for (int j = 0; j < (c - 1) % 4; j++)doss.moveLeftToRight(), up += doss.up;
        if (i < r - 1) {
            doss.moveUpToDown();
            up += doss.up;
        }
    }
    cout << up << endl;
    return 0;
}
