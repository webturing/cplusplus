#include<iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    for (float f; cin >> f;)
        cout << setiosflags(ios::fixed) << setprecision(2) << fabs(f) << endl;
    return 0;
}
