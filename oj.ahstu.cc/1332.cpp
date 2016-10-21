#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int a, b; cin >> a >> b;) {
        int s = 1;
        a %= 1000;
        for (int i = 0; i < b; i++)
            s = (s * a) % 1000;
        cout << setw(3) << setfill('0') << s << endl;
    }
    return 0;
}