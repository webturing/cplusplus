#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
int main(){
    freopen("input.txt", "r", stdin);
    int n = read();
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        v[i] = read();
    }
    int cnt = 0;
    int last = 0;
    for(auto i: v){
        if(i > last){
            cnt += (i - last) * 6;
        }else{
            cnt += (last - i) * 4;
        }
        last = i;
        cnt += 5;
    }
    cout << cnt << endl;
}