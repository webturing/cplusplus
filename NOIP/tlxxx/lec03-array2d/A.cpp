#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>v;// 向量
    while(n){
        v.push_back(n % 10);
        n /= 10;
    }
    cout << v.size() << endl;// 长度
    return 0;

}
