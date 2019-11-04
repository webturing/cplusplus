//排序去重的数组版本 使用STL算法unique
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
    int j = unique(a, a + n) - a;//不重复的元素个数，O(n)前提要求数组有序

    for (int i = 0; i < j; i++)cout << a[i] << " ";
    cout << endl;
    return 0;
}