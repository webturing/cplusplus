#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[]) {
    float a, b, c;
    cin >> a >> b >> c;
    float delta = b * b - 4 * a * c;
    float x1 = (-b + sqrt(delta)) / (2 * a);
    float x2 = (-b - sqrt(delta)) / (2 * a);
    cout << setiosflags(ios::fixed) << setprecision(2) << x1 << ' ' << x2 << endl;
    return 0;
}
