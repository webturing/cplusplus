//
// Created by ubuntu on 18-7-7.
//

#include <bits/stdc++.h>

using namespace std;
int n = 8;

int main() {
    int m = 4;
    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8};
    int sum = accumulate(a, a + n, 0);
    int left = *max_element(a, a + n);
    int right = sum;
    int best = sum;
    while (left < right) {
        int mid = (left + right) >> 1;
//        cout << "LEFT: " << left << "    RIGHT: " << right << "  MID  :    " << mid <<   endl;

        int s = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (t > m) {
                break;
            }
            if (s + a[i] > mid) {
                t++;
                s = a[i];
            } else {
                s += a[i];
            }
        }

//        cout << "T:  " << t <<"  MID: " << mid << endl;
        if (t <= m) {
            if (t == m) {
                best = min(best, right);
            }
            right = mid;
        } else {
            left = mid + 1;
        }
    }
//    cout << left +1 << endl;
//    cout << right << endl;
    cout << best << endl;
}