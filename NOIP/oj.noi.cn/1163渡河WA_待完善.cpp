#include <bits/stdc++.h>

using namespace std;
#define  LOCAL

int main() {
    ifstream cin("input.txt");
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<int> > east;
    priority_queue<int, vector<int>, greater<int> > west;
    vector<int> t(n);
    for (auto &e:t)cin >> e;
    sort(t.begin(), t.end());
    int tot = max(t[0], t[1]);
    west.push(t[0]);
    west.push(t[1]);
    t.erase(t.begin(), t.begin() + 2);
    for (auto e:t)east.push(e);
    while (east.size()) {
#ifdef LOCAL
        priority_queue<int, vector<int>, less<int> > east2(east);
        priority_queue<int, vector<int>, greater<int> > west2(west);
        while (east2.size()) {
            cerr << east2.top() << " ";
            east2.pop();
        }
        while (west2.size()) {
            cerr << west2.top() << " ";
            west2.pop();
        }
        cerr << endl;
#endif
        int a = west.top();
        west.pop();
        tot += a;
        east.push(a);
        int x = east.top();
        east.pop();
        int y = east.top();
        east.pop();
        tot += max(x, y);

        west.push(x);
        west.push(y);
#ifdef LOCAL
        priority_queue<int, vector<int>, less<int> > east3(east);
        priority_queue<int, vector<int>, greater<int> > west3(west);
        while (east3.size()) {
            cerr << east3.top() << " ";
            east3.pop();
        }
        cerr << "|->|";
        while (west3.size()) {
            cerr << west3.top() << " ";
            west3.pop();
        }
        cerr << endl;


#endif

    }
    cout << tot << endl;
    return 0;
}