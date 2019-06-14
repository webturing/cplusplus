#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v{1, 3, 5, 8, 7, 9, 4};
    vector<int> w(v.size());
    auto pos = copy_if(v.begin(), v.end(), w.begin(), [](int x) {
        return x & 1;
    });
    w.erase(pos, w.end());
    copy(w.begin(), w.end(), ostream_iterator<int>(cout, " "));

    return 0;
}