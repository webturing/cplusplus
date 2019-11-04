#include <bits/stdc++.h>

using namespace std;

void op(char &c) {
    if (isupper(c))_tolower(c);
    else _toupper(c);
}

int main() {
    string line;
    getline(cin, line);
    transform(line.begin(), line.end(), op);
    cout << line << endl;
    return 0;
}