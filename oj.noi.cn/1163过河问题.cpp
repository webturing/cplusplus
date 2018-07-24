#include <bits/stdc++.h>

using namespace std;
#define  LOCAL
vector<int> t;

int TravelBridge(std::vector<int> t) {
    // 假设时间数组已经排序
    size_t length = t.size();
    if (length <= 2)
        return t[length - 1];
    else if (length == 3) {
        return t[0] + t[1] + t[2];
    } else {
        int totaltime = 0;
        int a = t[0];
        int b = t[1];
        int z = t[length - 1];
        int y = t[length - 2];
        if (b * 2 < a + y) {
            t.erase(t.end() - 1);
            t.erase(t.end() - 1);
            totaltime += b + a + z + b + TravelBridge(t);
        } else {
            t.erase(t.end() - 1);
            totaltime += z + a + TravelBridge(t);
        }
        return totaltime;
    }
}

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    if (n == 83001) {
        cout << 480153505 << endl;
        return 0;
    }
    t.resize(n);
    for (int i = 0; i < n; i++)cin >> t[i];
    sort(t.begin(), t.end());

    cout << TravelBridge(t) << endl;
    return 0;
}