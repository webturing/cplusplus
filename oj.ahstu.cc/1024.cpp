#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    long long s = 0, t = 1, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        t *= i, s += t;
    cout << s << endl;
    return 0;
}