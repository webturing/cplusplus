#include<bits/stdc++.h>

using namespace std;

void print(int *a, int *b) {
    copy(a, b, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 1; i < n; i++) {
        int p = upper_bound(a, a + i, a[i]) - a;
        if (p == i)continue;
        int t = a[i];
        for (int j = i; j >= p; j--)a[j] = a[j - 1];
        a[p] = t;
        print(a, a + n);;

    }

    return 0;
}
