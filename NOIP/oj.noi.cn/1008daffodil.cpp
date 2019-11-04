#include <bits/stdc++.h>

using namespace std;

int main() {
    int flowers[] = {153, 371, 370, 407};
    int n = sizeof(flowers) / sizeof(flowers[0]);
    int x;
    cin >> x;
    if (find(flowers, flowers + n, x) != flowers + n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}