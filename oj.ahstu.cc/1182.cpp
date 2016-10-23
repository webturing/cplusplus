#include<iostream>

using namespace std;


int main() {
    int n;
    string s;
    for (cin >> n; n-- && cin >> s;) {
        for (string::const_iterator it = s.begin(); it != s.end(); ++it)
            if (isupper(*it))
                cout << (char) tolower(*it);
            else if (islower(*it))
                cout << (char) toupper(*it);
            else
                cout << *it;
        cout << endl;

    }
    return 0;
}
