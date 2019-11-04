#include<iostream>
#include<set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> myset;
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        myset.insert(temp);
    }
    set<int>::iterator it = myset.begin();
    int cnt = 0;
    for (; it != myset.end(); it++) {
        if (myset.find(*it + 1) != myset.end()) {
            cnt++;
        }
        if (myset.find(*it - 1) != myset.end())
            cnt++;
    }
    cout << cnt / 2 << endl;
    return 0;
}
