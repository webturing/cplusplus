#include<iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using  namespace std;

int main(int argc, char const *argv[]) {
    int a[4];
    for (int i = 0; i < 4; i++)cin >> a[i];
    sort(a, a + 4);
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
    return 0;
}