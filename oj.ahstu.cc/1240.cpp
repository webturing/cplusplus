#include<iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, a, b;
    for (cin >> n; n-- && cin >> a >> b; cout << a + b << endl);
    return 0;
}
