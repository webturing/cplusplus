#include<iostream>

using namespace std;


int main() {
    for (string s; getline(cin, s);) {
        for (string::const_iterator it = s.begin(); it != s.end(); ++it)
            if (!isspace(*it))
                cout << *it;
        cout << endl;

    }
    return 0;
}
