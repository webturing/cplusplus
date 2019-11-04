#include <bits/stdc++.h>

using namespace std;

void char2int(char &c) {
    c -= '0';
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    for_each(s.begin(), s.end(), char2int);
    cout << accumulate(s.begin(), s.end(), 0) << endl;
    return 0;
}
