#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[0] + v[1] < v[2]) {
        cout << "NO" << endl;
    } else if (v[0] == v[1] && v[1] == v[2]) {
        cout << "Equilateral" << endl;
    } else if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
        cout << "Right" << endl;
    } else {
        cout << "General" << endl;
    }
    return 0;
}