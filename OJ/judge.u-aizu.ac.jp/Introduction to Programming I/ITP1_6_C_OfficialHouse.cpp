#include <bits/stdc++.h>

using namespace std;
int B[4][3][10];

void disp() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                cout << " ";
                cout << B[i][j][k];
            }
            cout << endl;
        }
        if (i < 3)
            cout << "####################" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int b, f, r, v;
        cin >> b >> f >> r >> v;
        B[b - 1][f - 1][r - 1] += v;
    }
    disp();
    return 0;
}