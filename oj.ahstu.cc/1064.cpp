#include<iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(int argc, char const *argv[]) {
    for (float r, pi = atan(1.) * 4; cin >> r;)
        cout << setiosflags(ios::fixed) << setprecision(3) << 4. / 3 * pi * r * r * r << endl;
    return 0;
}
