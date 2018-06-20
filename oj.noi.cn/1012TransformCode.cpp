#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int t = n % 123;
    if (t >= 97)
        cout << (char) t << endl;
    else {
        t = n % 91;
        if (t >= 65)
            cout << (char) t << endl;
        else
            cout << "*" << endl;
    }


    return 0;
}
