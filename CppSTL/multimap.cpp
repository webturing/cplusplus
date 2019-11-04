#include<bits/stdc++.h>

using namespace std;

//任意映射的打印方法 支持 map/multiMap vector<pair<>>等 方便调试
template<typename T>
void printM(T a, string s = "") {
    cout << s << ":\t";
    for (auto e:a) {
        cout << e.first << "," << e.second << " ";
    }
    cout << endl;
}

int main() {
    vector<pair<int, int> > a;
    multimap<int, int> M;//多重映射，用平衡树实现,常用操作都是O(lgN)
    for (int i = 0; i < 10; i++) {
        int t = rand() % 10;
        a.push_back(make_pair(t, i));
        M.insert(make_pair(t, i));//插入
    }
    printM(a, "elements in Vector");
    printM(M, "elements in Multimap");
    auto x = M.equal_range(4);//返回一个区间pair 该区间的[left,right)的值都是val O(lgN)
    for (auto p = x.first; p != x.second; ++p)//树和链表迭代器都不支持 <判断，只能进行!= 和++ --操作
        cout << p->first << "," << p->second << " ";
    cout << endl;
    return 0;
}