#include <iostream>

using namespace std;

int main() {
    int x, y, sum = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i++)
        if (i % 3 == 1 && i % 5 == 3)
            sum += i;
    cout << sum << endl;
    return 0;
}