#include<bits/stdc++.h>

using namespace std;

//任意容器的打印方法 支持 vector list set multiset等 方便调试
template<typename T>
void print(T a, string s = "") {
    cout << s << ":\t";
    for (auto e:a) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a;
    multiset<int> M;//多重集，用平衡树实现,常用操作都是O(lgN)
    for (int i = 0; i < 10; i++) {
        int t = rand() % 10;
        a.push_back(t);
        M.insert(t);//插入
    }
    print(a, "elements in Vector");
    print(M, "elements in MultiSet");
    auto x = M.equal_range(4);//返回一个区间pair 该区间的[left,right)的值都是val O(lgN)
    for (auto p = x.first; p != x.second; ++p)//树和链表迭代器都不支持 <判断，只能进行!= 和++ --操作
        cout << *p << " ";
    cout << endl;
    return 0;
}