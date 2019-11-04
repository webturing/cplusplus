#include<bits/stdc++.h>

using namespace std;

void print(int *a, int *b) {
    copy(a, b, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int pp(int *A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j >= r - 1; j--) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void qsort(int *a, int from, int to) {
    if (from >= to)return;
    int p = pp(a, from, to);

    qsort(a, from, p - 1);
    qsort(a, p + 1, to);
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int n = sizeof(a) / sizeof(a[0]);
    qsort(a, 0, n - 1);
    print(a, a + n);
    return 0;
}
