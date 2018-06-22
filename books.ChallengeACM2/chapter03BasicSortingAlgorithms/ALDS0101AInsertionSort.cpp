#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int j = i + 1;
        auto idx = upper_bound(v.begin(), v.begin() + j, v[j]) - v.begin();
        if (idx == j) continue;
        int t = v[j];
        for (int k = j; k > idx; k--) {
            v[k] = v[k - 1];
        }
        v[idx] = t;
        copy(v.begin(), v.begin() + j + 1, ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    insertionSort(v);
    return 0;
}
