//
// Created by jal on 18-7-20.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    vector<int> fib;
    fib.push_back(7);
    fib.push_back(10);
    while (true) {
        int t = *fib.rbegin() + (*(fib.rbegin() + 1));
        fib.push_back(t);
        if (t > n)break;
    }
    for (auto i = fib.rbegin(); i != fib.rend(); i++) {
        if (*i < n) {
            n -= *i;
        }
    }
    cout << n << endl;
}