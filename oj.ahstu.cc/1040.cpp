#include<iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(int argc, char const *argv[]) {
    for (int n; cin >> n;) {
        if (n % 2 == 0)n--;
        cout << (1 + n) * (1 + n) / 4 << endl;
    }
    return 0;
}