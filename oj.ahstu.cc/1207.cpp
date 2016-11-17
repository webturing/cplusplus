#include<iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int n; cin >> n && n;) {
        int a = n / 100, b = n / 10 % 10, c = n % 10;
        cout << (n < 1000 && n >= 100 && n == a * a * a + b * b * b + c * c * c ? "Yes" : "No") << endl;
    }
    return 0;
}
