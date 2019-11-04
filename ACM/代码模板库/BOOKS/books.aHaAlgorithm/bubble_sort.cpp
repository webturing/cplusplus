//
// Created by jal on 18-9-2.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[10] = {4, 3, 5, 3, 6, 1, 2, 9, 8, 7};
    int len = sizeof(a) / sizeof(a[0]);
    for (int i = 1; i <= len - 1; i++) {
        for (int j = 0; j < len - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    copy(a, a + len, ostream_iterator<int>(cout, " "));
}