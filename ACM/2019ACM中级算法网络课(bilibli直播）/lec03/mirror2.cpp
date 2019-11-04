#include<bits/stdc++.h>

using namespace std;

bool sysmetric(string s) {
    string t = s;//t是s的副本
    reverse(t.begin(), t.end());//t=>t'
    return s == t;//s>t s<t 比较是字典序
}

int main() {
    string s;
    cin >> s;
    // cout << (s + s) << endl;//strcat
    // reverse(s.begin(), s.end());
    // cout << s << endl;
    cout << "sysmetric?" << sysmetric(s) << endl;
    if (s.size() % 2 == 0 and s.size() > 0 and sysmetric(s)) {
        s = s.substr(0, s.size() / 2);
        cout << s << endl;//还原一次魔镜操作
    }
    return 0;
}

