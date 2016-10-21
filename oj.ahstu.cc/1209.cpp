#include<iostream>
#include <cmath>
#include <iomanip>

using  namespace std;

int main(int argc, char const *argv[]) {
    float u, d, h, slope, area, perimeter;
    cin >> u >> d >> h;
    slope = hypot(h, (d - u) / 2);
    area = (u + d) * h / 2;
    perimeter = u + d + 2 * slope;
    cout << setiosflags(ios::fixed) << setprecision(2)
    << area << endl
    << perimeter << endl;
    return 0;
}