#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;
    string sa, sb;
    cin >> sa >> sb;

    map<char, list<int>> a, b;
    int i = 1;
    for (auto c:sa) a[c].push_front(i++);
    i = 1;
    for (auto c:sb)b[c].push_front(i++);

    int tot = a['?'].size() + b['?'].size();
    for (auto c = 'a'; c <= 'z'; ++c) {
        int match = min(a[c].size(), b[c].size());
        tot += match;
    }
    tot = min(n, tot);
    cout << tot << endl;
    for (auto c = 'a'; c <= 'z'; ++c) {
        int match = min(a[c].size(), b[c].size());
        for (int i = 0; i < match; i++) {
            cout << a[c].front() << " " << b[c].front() << endl;
            a[c].pop_front();
            b[c].pop_front();
        }
    }
    list<int> la, lb;
    for (char c = 'a'; c <= 'z'; c++) {
        la.merge(a[c]);
        lb.merge(b[c]);
    }
    while (lb.size() and a['?'].size()) {
        cout << a['?'].front() << " " << lb.front() << endl;
        a['?'].pop_front();
        lb.pop_front();
    }
    while (la.size() and b['?'].size()) {
        cout << la.front() << " " << b['?'].front() << endl;
        b['?'].pop_front();
        la.pop_front();
    }
    while (a['?'].size() and b['?'].size()) {
        cout << a['?'].front() << " " << b['?'].front() << endl;
        a['?'].pop_front();
        b['?'].pop_front();
    }


    return 0;
}
