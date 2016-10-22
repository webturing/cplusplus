#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    for (unsigned n, s; cin >> n;) {
        for (s = 0; n; n /= 10)s += n % 10;
        cout << s << endl;
    }
    return 0;
}