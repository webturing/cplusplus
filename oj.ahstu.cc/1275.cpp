#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<double> v(3);
    for (auto &d:v)cin >> d;
    cout << fixed << setprecision(3) << accumulate(v.begin(), v.end(), 0.0) / v.size() << endl;
    return 0;
}