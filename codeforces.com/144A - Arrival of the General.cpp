#include<bits/stdc++.h>

using namespace std;

template<typename T>
void oo(string str, T val) {
    cerr << str << val << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e:a)cin >> e;
    int left = max_element(a.begin(), a.end()) - a.begin();
    int right = 0;
    for (int i = 1; i < n; i++)
        if (a[i] <= a[right])right = i;
//    oo("left=", left);
//    oo("right=", right);
    if (left < right)
        cout << (n - 1 - right) + left << endl;
    else
        cout << (n - 2 - right) + left << endl;
    return 0;
}
