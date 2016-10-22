#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    for (int a, b; cin >> a >> b && (a || b); cout << (b - a + 1) * (b + a) / 2 << endl);
    return 0;
}