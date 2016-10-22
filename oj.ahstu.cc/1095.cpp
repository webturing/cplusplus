#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    for (string s; cin >> s;) {
        for (string::const_iterator it = s.begin(); it != s.end(); ++it)
            cout << (char) toupper(*it);
        cout << endl;
    }
    return 0;
}
