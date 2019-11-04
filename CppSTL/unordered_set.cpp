#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v(10);
    for_each(v.begin(), v.end(), [](int &x) {
        x = rand() % 100;
    });
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    set<int> S(v.begin(), v.end());
    copy(S.begin(), S.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    unordered_set<int> T(v.begin(), v.end());
    copy(T.begin(), T.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}