#include<iostream>
#include <cmath>

using namespace std;

int main() {
    for (float x; cin >> x; cout << (int) (log10(x) + 1) << endl);
    return 0;
}
