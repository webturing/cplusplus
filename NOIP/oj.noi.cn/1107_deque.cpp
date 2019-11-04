//
// Created by ubuntu on 18-7-2.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    deque<string> d;
    for (int i = 0; i < n; i++) {
        int op;
        string x;
        cin >> op >> x;
        if (op == 0) {
            d.push_front(x);
        } else if (op == 1) {
            d.push_back(x);
        }
    }
    for (auto i:d) {
        cout << i << endl;
    }
}