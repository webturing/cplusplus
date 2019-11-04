#include<bits/stdc++.h>

using namespace std;

void print(const vector<int> &v) {
    for (auto i:v)cout << i << " ";
    cout << endl;
}

int main() {
    int n = 6;
    cin >> n;
    int m = sqrt(2 * n) + 1;
    vector<int> a(m, 1);
    partial_sum(a.begin(), a.end(), a.begin());
    partial_sum(a.begin(), a.end(), a.begin());

    if (binary_search(a.begin(), a.end(), n)) {//log(N)
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}