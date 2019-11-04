#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>

using namespace std;
int a[10];

int main() {
    string s;
    cin >> s;
    a[0] = s[0] - '0';
    a[1] = s[2] - '0';
    a[2] = s[3] - '0';
    a[3] = s[4] - '0';
    a[4] = s[6] - '0';
    a[5] = s[7] - '0';
    a[6] = s[8] - '0';
    a[7] = s[9] - '0';
    a[8] = s[10] - '0';
    a[9] = s[12] - '0';
    int sum = 0;
    for (int i = 0, j = 1; i < 9; i++, j++) {
        sum += a[i] * j;
    }
    int code = sum % 11;
    char c = code == 10 ? 'X' : '0' + code;
    if (s[12] == c) {
        cout << "Right" << endl;
    } else {
        s[12] = c;
        cout << s << endl;
    }
    return 0;
}
