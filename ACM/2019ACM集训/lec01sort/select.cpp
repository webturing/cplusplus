#include<bits/stdc++.h>

using namespace std;

void print(int *a, int *b) {
    copy(a, b, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n - 1; i++) {
        int j = min_element(a + i, a + n) - a;
        swap(a[i], a[j]);
        print(a, a + n);
    }

    return 0;
}
