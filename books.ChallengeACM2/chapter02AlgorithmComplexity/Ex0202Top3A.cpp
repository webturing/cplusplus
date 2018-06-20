#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    //find max3 O(3*n)
    vector<int> S(10);
    for (auto &i:S) {
        cin >> i;
    }
    vector<int> ans(3);
    for (int i = 0; i < ans.size(); i++) {
        auto idx = max_element(S.begin(), S.end());
        ans[i] = *idx;
        *idx = -1;//delete max1
    }
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
