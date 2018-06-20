#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[]) {
//    ifstream cin("input.txt");
    string e;
    cin >> e;
//    cerr << "e=" << e << endl;
    stack<char> sc;
    stack<int> sl;
    for (int i = 0; i < e.length(); i++) {
        if (e[i] == '(') {
            sc.push(e[i]);
            sl.push(i);
        } else if (e[i] == ')') {
            int r = i;
            int l = sl.top();
            sc.pop();
            sl.pop();
            cout << l << " " << r << endl;
        }
    }
    return 0;

}