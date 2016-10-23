#include<iostream>

using namespace std;

int rev(int n) {
    int m = 0;
    for (; n; n /= 10)m = m * 10 + n % 10;
    return m;
}

int main() {
    for (int a, b; cin >> a >> b; cout << rev(rev(a) * rev(b)) << endl);
    return 0;
}
