#include<iostream>

using namespace std;

int main() {
    for (string s; getline(cin, s);) {
        cout << (char) toupper(s[0]);
        for (unsigned i = 1; i < s.length(); i++)
            if (isalpha(s[i]) && isspace(s[i - 1]))
                cout << (char) toupper(s[i]);
            else
                cout << s[i];
        cout << endl;
    }
    return 0;
}
