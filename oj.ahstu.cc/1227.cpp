#include<iostream>

using namespace std;


int main() {
    int n;
    string s;
    for (cin >> n; n-- && cin >> s;) {
        int tot = 0;
        for (string::const_iterator it = s.begin(); it != s.end(); ++it)
            if (isdigit(*it))++tot;
        cout << tot << endl;
    }
    return 0;
}
