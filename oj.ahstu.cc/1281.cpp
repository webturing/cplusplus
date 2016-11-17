#include<iostream>
#include <iomanip>

using  namespace std;

int main() {
    int n;
    cin >> n;
    float s = 95 * n;
    if (s >= 300)s *= 0.85;
    cout << setiosflags(ios::fixed) << setprecision(2) << s << endl;
    return 0;
}