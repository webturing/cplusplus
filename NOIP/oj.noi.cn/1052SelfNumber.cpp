#include <bits/stdc++.h>

using namespace std;

int d(int n) {
    int ret = n;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

const int maxn = 1e+7 + 1;
char B[maxn] = {0};

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;


    for (int i = 1; i <= n; i++)
        if (d(i) <= n)
            B[d(i)] = 1;
    vector<int> selfNumbers;
    for (int i = 1; i <= n; i++)
        if (!B[i]) {
            selfNumbers.push_back(i);
        }
    //copy(selfNumbers.begin(), selfNumbers.begin() + n + 1, ostream_iterator<int>(cout, " "));
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        ans.push_back(selfNumbers[t - 1]);
    }
    cout << selfNumbers.size() << endl;
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}