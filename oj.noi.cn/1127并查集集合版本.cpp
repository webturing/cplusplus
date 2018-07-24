#include <bits/stdc++.h>

using namespace std;
set<set<int>> f;
int n, k;

void merge(int a, int b) {
    if (a == b)return;
    set<set<int>>::iterator x, y;
    for (x = f.begin(); x != f.end(); ++x) {
        if (x->find(a) != x->end())break;
    }
    for (y = f.begin(); y != f.end(); ++y) {
        if (y->find(b) != y->end())break;
    }
    if (x == y)
        return;
    set<int> g;
    for (auto i:*x) {
        g.insert(i);
    }
    for (auto i:*y) {
        g.insert(i);
    }
    f.erase(x);
    f.erase(y);
    f.insert(g);

}

int main() {
    ifstream cin("input.txt");
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        set<int> s;
        s.insert(i);
        f.insert(s);
    }

    while (k--) {
        int a, b;
        cin >> a >> b;
        if (a > b)swap(a, b);
        merge(a, b);
    }
    int mx = f.begin()->size();
    for (auto i:f)
        if (i.size() > mx)mx = i.size();
    cout << f.size() << " " << mx << endl;

    return 0;
}