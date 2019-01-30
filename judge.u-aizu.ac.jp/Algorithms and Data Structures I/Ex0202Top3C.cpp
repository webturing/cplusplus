#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> S(10);
    for (auto &i : S) cin >> i;
    vector<int> C(101, 0);
    for (auto s : S) {
        C[s]++;
    }
    int cnt = 3;
    for (int p = 100; cnt && p >= 0; p--) {
        while (C[p] && cnt) {
            cout << p << " ";
            --cnt;
        }
    }
    return 0;
}
