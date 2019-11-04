#include<bits/stdc++.h>

using namespace std;
const int maxn = 2000;
const int maxm = 85000;
int a[maxn * maxn];

int cmp(int a, int b) {
    return rand() & 1;
}


int main() {
    cout << 2000 << endl;
    srand(time(NULL));
    for (int i = 0; i < maxm; i++)
        a[i] = 1;
    sort(a, a + maxn * maxn, cmp);
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++)
            cout << a[i * maxn + j];
        cout << endl;
    }

}