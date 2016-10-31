#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int cas, n, ret, tot;
    for (cin >> cas; cas-- && cin >> n;) {
        for (ret = tot = 1; ret != 6174;) {
            vector<int> d(4);
            for (int i = 0; i < 4; i++) {
                d[i] = n % 10;
                n /= 10;
            }
            sort(d.begin(), d.end());
            ++tot;
            ret = (1000 * d[3] + 100 * d[2] + 10 * d[1] + d[0]) - (1000 * d[0] + 100 * d[1] + 10 * d[2] + d[3]);
            n = ret;
        }
        cout << tot << endl;
    }
    return 0;
}
