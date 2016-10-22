#include<iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

    for (int n, m; cin >> n >> m;) {
        double sum = 0;
        for (int i = n; i <= m; i++)
            sum += 1.0 / i / i;
        cout << setiosflags(ios::fixed) << setprecision(5) << sum << endl;
    }
    return 0;
}