#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<string>

using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    for (string::const_iterator it = s.begin(); it != s.end(); ++it)
        if (isalpha(*it))
            cout << *it;
    cout << endl;
    return 0;
}
