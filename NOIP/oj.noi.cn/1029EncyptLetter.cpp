#include <bits/stdc++.h>

using namespace std;

void encode(char &c) {
    if (isalpha(c)) {
        if (islower(c)) {
            c = (c - 'a' + 3) % 26 + 'a';
        } else {
            c = (c - 'A' + 3) % 26 + 'A';
        }
    }
}

int main(int argc, char const *argv[]) {
    string s;
    getline(cin, s);
    for_each(s.begin(), s.end(), encode);
    cout << s << endl;
    return 0;
}