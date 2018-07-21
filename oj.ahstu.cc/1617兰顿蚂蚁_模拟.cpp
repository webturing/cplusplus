#include <bits/stdc++.h>

using namespace std;


const int WHITE = 0;
const int BLACK = 1;
const string DIRECTION = "URDL";
int M[101][101] = {0};
int m, n;
int x, y;
char direction;
int k;
map<char, char> inc_clock, dec_clock;

inline void U() { x--; }

inline void D() { x++; }

inline void L() { --y; }

inline void R() { ++y; }

void init() {
    for (int i = 0; i < 4; i++) {
        inc_clock[DIRECTION[i]] = DIRECTION[(i + 1) % 4];
        dec_clock[DIRECTION[i]] = DIRECTION[(i + 3) % 4];
    }
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    string temp;
    cin >> x >> y >> temp >> k;
    direction = temp[0];
}

void step() {
    if (M[x][y] == BLACK) {
        direction = inc_clock[direction];
        M[x][y] = WHITE;
    } else {
        direction = dec_clock[direction];
        M[x][y] = BLACK;
    }
    switch (direction) {
        case 'L':
            L();
            break;
        case 'R':
            R();
            break;
        case 'D':
            D();
            break;
        case 'U':
            U();
            break;
    }
}

int main() {
    for (init(); k--; step());
    cout << x << " " << y << endl;
    return 0;
}