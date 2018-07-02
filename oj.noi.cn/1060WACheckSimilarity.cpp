#include <bits/stdc++.h>

using namespace std;
const int maxn = 200 + 10;

int main() {
    ifstream cin("input.txt");
    char a[maxn], b[maxn];
    cin.getline(a, maxn);
    cin.getline(b, maxn);
    for (int i = 0; i < min(strlen(a), strlen(b)); i++) {
        if (a[i] == b[i])
            cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}
