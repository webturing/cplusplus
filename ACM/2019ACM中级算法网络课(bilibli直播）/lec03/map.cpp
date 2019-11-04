//map基本应用 map<K,V> 里面每一个节点都是pair<K,V>，整体数据结构是一个排序树
#include<bits/stdc++.h>

using namespace std;


int main() {
    ifstream cin("input.txt");
    map<string, int> M;
    for (string s; cin >> s;) {
        M[s]++;
    }
    for (auto e:M) {
        cout << e.first << ":" << e.second << endl;
    }
    return 0;
}