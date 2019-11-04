#include <bits/stdc++.h>

using namespace std;
enum {
    TOP = 1,
    FRONT = 2,
    RIGHT = 3,
    LEFT = 4,
    BACK = 5,
    BASE = 6
};

struct Dice {
    int top, base, front, back, left, right;

    friend istream &operator>>(istream &is, Dice &dice) {
        is >> dice.top >> dice.front >> dice.right >> dice.left >> dice.back >>
           dice.base;
        return is;
    }

    void SS() {
        int top = this->back, base = this->front, front = this->top,
                back = this->base;
        this->top = top, this->base = base, this->front = front, this->back = back;
    }

    void NN() {
        int top = this->front, base = this->back, front = this->base,
                back = this->top;
        this->top = top, this->base = base, this->front = front, this->back = back;
    }

    void EE() {
        int top = this->left, base = this->right, left = this->base,
                right = this->top;
        this->top = top, this->base = base, this->left = left, this->right = right;
    }

    void WW() {
        int top = this->right, base = this->left, left = this->top,
                right = this->base;
        this->top = top, this->base = base, this->left = left, this->right = right;
    }
};

int main() {
    //ifstream cin("in.txt");
    Dice dice;
    string op;
    cin >> dice;
    int q, front, top;
    for (cin >> q; q-- and cin >> top >> front;) {
        while (dice.top != top or dice.front != front) {
            if (rand() % 2)dice.NN();
            if (rand() % 2)dice.SS();
            if (rand() % 2)dice.EE();
            if (rand() % 2)dice.WW();
        }
        cout << dice.right << endl;
    }

    return 0;
}