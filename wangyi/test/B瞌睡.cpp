//
// Created by jal on 18-9-8.
//

#include<bits/stdc++.h>

using namespace std;

void print(int *arr, int left, int right) {
    for (int i = left; i < right; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[right] << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n + 1], b[n + 1];
    int s_a[n + 1], s_b[n + 1]; //存储数组a前缀和; 存储有效听课时间前缀和
    s_a[0] = s_b[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        s_a[i] = s_a[i - 1] + a[i];
        s_b[i] = s_b[i - 1] + a[i] * b[i];
    }

    int MAX = s_b[n];
    for (int i = 1; i <= n; i++) {
        if (b[i]) continue;
        int right = min(n, i + k - 1);
        int t = s_b[i - 1] + s_b[n] - s_b[right] + s_a[right] - s_a[i - 1];
//        printf("%d %d %d %d %d t:%d \n",s_b[i-1],s_b[n],s_b[right],s_a[right],s_a[i-1],t);
        MAX = max(t, MAX);
    }
    cout << MAX << endl;
}