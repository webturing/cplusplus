#include<bits/stdc++.h>

using namespace std;

struct Set {
    set<char> s;

    friend istream &operator>>(istream &is, Set &set) {
        string buffer;
        is >> buffer;
        for (auto c:buffer)set.s.insert(c);
        return is;
    }

    friend ostream &operator<<(ostream &os, Set &set) {
        copy(set.s.begin(), set.s.end(), ostream_iterator<char>(os, ""));
        return os;
    }

    Set operator+(Set &that) {
        Set ans;
        for (auto c:this->s)ans.s.insert(c);
        for (auto c:that.s)ans.s.insert(c);
        return ans;
    }

    Set operator*(Set &that) {
        Set ans;
        for (auto c:this->s)
            if (that.s.find(c) != that.s.end())ans.s.insert(c);
        return ans;
    }

    Set operator-(Set &that) {
        Set ans;
        for (auto c:this->s)
            if (that.s.find(c) == that.s.end())ans.s.insert(c);
        return ans;
    }
};

int main() {
    ifstream cin("input.txt");
    int m;
    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        Set t;
        cin >> t;
        for (int i = 1; i < k; i++) {
            string op;
            Set cur;
            cin >> op >> cur;
            if (op == "+")
                t = t + cur;
            else if (op == "-")
                t = t - cur;
            else if (op == "*")
                t = t * cur;
        }
        cout << t << endl;
    }
    return 0;
}