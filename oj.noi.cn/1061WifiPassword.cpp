#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream cin("input.txt");
    for (string s; cin >> s;) {
        if (s == "N")
            break;
        if (s == "Y") {
            string password;
            cin >> password;
            if (password == "NOIP@CCF") {
                cout << "Success" << endl;
                break;
            } else {
                cout << "Sorry" << endl;
            }
        }
    }
    return 0;
}