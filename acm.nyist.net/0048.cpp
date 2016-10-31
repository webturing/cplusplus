#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
    set<int> s;
    for (int n; cin >> n;) {
        s.clear();
        for (int t; n-- && cin >> t; s.insert(t));
        cout << s.size() << endl;
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}
