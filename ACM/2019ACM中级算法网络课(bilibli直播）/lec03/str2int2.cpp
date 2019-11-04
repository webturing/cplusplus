#include<bits/stdc++.h>

using namespace std;

int main() {
    int n = 1234, m;
    ostringstream oss;
    oss << n % 10 << n / 10;//cout
    // cout << oss.str() << endl;//string
    istringstream iss(oss.str());
    iss >> m;//cin
    cout << m << endl;


}
