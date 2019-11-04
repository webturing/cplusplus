#include<bits/stdc++.h>

using namespace std;

int main() {
    int y;
    cin >> y;
    for (int z = y + 1;; z++) {
        map<int, int> d;
        for (int t = z; t; t /= 10)d[t % 10]++;
        if (d.size() == 4) {
            cout << z << endl;
            break;
        }
    }
    return 0;
}