#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> S(10);
    for (auto &i : S) {
        cin >> i;
    }
    sort(S.begin(), S.end());
    copy(S.rbegin(), S.rbegin() + 3, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
