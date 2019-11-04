#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v;
    while (n > 1 && (n & 1) == 0) {
        v.push_back(2);
        n >>= 1;
    }
    for (int c = 3; n > 1; c += 2) {
        while (n % c == 0) {
            v.push_back(c);
            n /= c;
        }
    }
    copy(v.begin(), v.end() - 1, ostream_iterator<int>(cout, "*"));
    cout << *v.rbegin() << endl;

    return 0;
}