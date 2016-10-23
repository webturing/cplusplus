#include<iostream>

using namespace std;

int main() {
    for (int a, b; cin >> a >> b;) {
        if (a < 100)a = 100;
        if (b > 999)b = 999;
        for (int n = a; n <= b; n++) {
            int x = n / 100, y = n / 10 % 10, z = n % 10;
            if (n == x * x * x + y * y * y + z * z * z)
                cout << n << endl;
        }
    }
    return 0;
}