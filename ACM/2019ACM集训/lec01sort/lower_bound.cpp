#include<bits/stdc++.h>

using namespace std;

void print(int *a, int *b) {
    copy(a, b, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    int a[] = {1, 2, 2, 2, 2, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    int left = lower_bound(a, a + n, k) - a;
    int right = upper_bound(a, a + n, k) - a;
    cout << k << " at range [" << left << "," << right << ")" << endl;
    cout << count(a, a + n, k) << endl;//k appear
    cout << right - left << endl;

    return 0;
}
