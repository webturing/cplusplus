#include<bits/stdc++.h>

using namespace std;

void print(int *a, int *b) {
    copy(a, b, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 7;
    print(a, a + n);
    sort(a, a + n);
    print(a, a + n);
    cout << binary_search(a, a + n, k) << endl;
    sort(a, a + n, greater<int>());
    print(a, a + n);
    cout << binary_search(a, a + n, k, greater<int>()) << endl;

    return 0;
}
