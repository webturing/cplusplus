//排序去重的数组版本
#include<bits/stdc++.h>

using namespace std;


int main() {
    int a[] = {1, 1, 6, 3, 3,};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a + 5);//排增序
    //sort(a, a + 5, greater<int>());//排降序
    //
    for (int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
    int b[5] = {0};
    int j = 0;
    b[j++] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] != b[j - 1])
            b[j++] = a[i];
    }
    for (int i = 0; i < j; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}