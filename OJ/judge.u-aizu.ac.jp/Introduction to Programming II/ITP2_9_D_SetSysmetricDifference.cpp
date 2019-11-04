#include <bits/stdc++.h>

using namespace std;

int nextInt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    int n;
    cin >> n;
    set<int> A;
    while (n--) A.insert(nextInt());
    int m;
    cin >> m;
    set<int> B;
    while (m--) B.insert(nextInt());
    set<int> C;
    for (auto a : A)
        if (B.find(a) == B.end()) C.insert(a);
    for (auto b : B)
        if (A.find(b) == A.end()) C.insert(b);
    for (auto c : C) cout << c << endl;

    return 0;
}