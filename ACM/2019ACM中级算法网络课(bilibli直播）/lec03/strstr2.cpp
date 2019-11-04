#include<bits/stdc++.h>

using namespace std;

int main() {
    string s("to know everything is to know nothing");
    string t = "to";
    auto pos = s.find(t);
    if (pos == string::npos) {//npos string中内置的一个静态常数，表示不可能的位置
        cout << "not found!" << endl;
    } else {
        cout << pos << endl;
    }
    pos = s.find(t, pos + t.size());
    cout << pos << endl;
    return 0;
}

