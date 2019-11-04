#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int m = n % 9;
    if (n > 0 && m == 0)m += 9;
    cout << m << endl;

    return 0;
}
