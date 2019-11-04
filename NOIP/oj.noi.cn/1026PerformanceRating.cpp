#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> v((istream_iterator<int>(cin)), istream_iterator<int>());
    sort(v.begin(), v.end());
    cout << setiosflags(ios::fixed) << setprecision(3)
         << 1.0 * accumulate(v.begin() + 1, v.end() - 1, 0) / (v.size() - 2) << endl;
    return 0;
}
