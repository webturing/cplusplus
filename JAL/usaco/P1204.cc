#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> pt(N);
    for (int i = 0; i < N; i++) cin >> pt[i].first >> pt[i].second;
    sort(pt.begin(), pt.end());
    int busy = 0, idle = 0;
    int cbusy = pt[0].second - pt[0].first;
    int cidle = 0;
    busy = cbusy;
    for (size_t i = 1; i < pt.size(); i++) {
        if (pt[i].second < pt[i - 1].second) {
            pt[i].second = pt[i - 1].second;
            continue;
        }
        if (pt[i].first <= pt[i - 1].second) {
            cbusy += pt[i].second - pt[i - 1].second;
        } else {
            cidle = pt[i].first - pt[i - 1].second;
            cbusy = pt[i].second - pt[i].first;
        }
        busy = max(busy, cbusy);
        idle = max(idle, cidle);
    }
    cout << busy << " " << idle << endl;
    return EXIT_SUCCESS;
}