#include<bits/stdc++.h>

using namespace std;


int main() {
    vector<int> v;
    for (int i = 0; i < 10; i++)v.push_back(i);
    //输出形式
    for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
    cout << endl;
    //C++11的输出
    for (auto i:v)cout << i << " ";
    cout << endl;
    v.push_back(10);//0~10
    v.pop_back();//O(1) 0~9
    v.erase(v.begin());//1~9 O(n)
    sort(v.begin(), v.end());

    return 0;
}