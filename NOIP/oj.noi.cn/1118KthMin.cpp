#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    priority_queue<int> q;
    for (int t; n-- && cin >> t;)q.push(t);
    while (q.size() > k) {
        q.pop();
    }
    cout << q.top() << endl;
    return 0;
}