//排序去重的set版本
#include<bits/stdc++.h>

using namespace std;


int main() {
    int a[] = {1, 1, 6, 3, 3,};
    set<int> S;//排序树（红黑树）实现的集合
    for (int i = 0; i < 5; i++)S.insert(a[i]);//如果a[i]不在这个集合中O(logN)，就把a[i]元素放入这个树种依然保持树的有序性O(logN)
    cout << S.size() << endl;
    for (auto e:S)//for each
        cout << e << " ";
    cout << endl;
    return 0;
}