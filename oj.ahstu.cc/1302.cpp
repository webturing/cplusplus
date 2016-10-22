#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    getline(cin, s);
    for (string::iterator it = s.begin(); it != s.end(); ++it)
        if (islower(*it))cout << (char) toupper(*it);
        else
            cout << (char) (*it);
    cout << endl;
    return 0;
}