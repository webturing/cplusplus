#include <bits/stdc++.h>

using namespace std;

int str2int(const string &s, int r) {
    int ret = 0;
    for (auto c:s) {
        ret = ret * r + c - '0';
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    assert(str2int("123", 10) == 123);
    string p, q, r;
    cin >> p >> q >> r;
    string t = p + q + r;
    int mm = *max_element(t.begin(), t.end()) - '0';
    bool find = false;
    for (int B = mm + 1; B <= 16; ++B) {
        if (str2int(p, B) * str2int(q, B) == str2int(r, B)) {
            find = true;
            cout << B << endl;
            break;
        }
    }
    if (!find) { cout << 0 << endl; }

    return 0;
}