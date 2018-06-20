#include <bits/stdc++.h>


using namespace std;

bool primer(int n) {
    if (n == 2)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    for (int c = 3; c * c <= n; c += 2) {
        if (n % c == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        if (primer(m)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;

}

