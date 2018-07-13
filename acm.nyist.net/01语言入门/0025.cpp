
#include<iostream>
#include<string>

using namespace std;

string trans(string a) {
    string b = "";
    if (a[1] == '#') {
        b += char((a[0] - 'A' + 1) % 7 + 'A');
        b += 'b';
    } else {
        b += char((a[0] - 'A' + 6) % 7 + 'A');
        b += '#';
    }
    return b;
}

int main() {
    string a, b;
    for (int t = 1; cin >> a >> b; t++) {
        cout << "Case " << t << ": ";
        if (a.length() == 1)
            cout << "UNIQUE" << endl;
        else
            cout << trans(a) << " " << b << endl;
    }
    return 0;
}
        