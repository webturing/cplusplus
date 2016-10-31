#include<iostream>

using namespace std;

int main() {
    int i, j, k, m, n, s;
    for (cin >> s; s-- && cin >> n >> m;) {
        for (i = m, j = 0; i <= n; i++)
            for (k = i; !(k % m); j++)
                k = k / m;
        cout << j << endl;
    }
    return 0;
}