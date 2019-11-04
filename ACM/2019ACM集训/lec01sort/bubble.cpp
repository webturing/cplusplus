#include<bits/stdc++.h>

using namespace std;

void print(int *a, int *b) {
    copy(a, b, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= i; j--) {
            if (a[j] > a[j + 1])swap(a[j], a[j + 1]);
        }
        print(a, a + n);
    }

    return 0;
}
