#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a{1, 2, 3, 6, 5, 4, 7};
    auto p = is_sorted_until(a.begin(), a.end());

    copy(a.begin(), p, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << is_sorted(a.begin(), a.end()) << endl;

    sort(a.begin(), a.end());

    cout << is_sorted(a.begin(), a.end()) << endl;

    return 0;
}