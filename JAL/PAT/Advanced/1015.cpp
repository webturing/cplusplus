#include <bits/stdc++.h>
using namespace std;
template<typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
template <typename T = int>
void OO(vector<T>v, string s=""){
    cerr<<s <<":"<< endl;
    for(auto i: v){
        cerr << i << ' ';
    }
    cerr << endl;
}
typedef unsigned long long ll;
int getReverse(int n, int b){
    int ret = 0;
    while(n){
        ret = ret * b + n % b;
        n /= b;
    }
    return ret;
}
bool prime(int n){
    if(n == 2)return 1;
    if(n <= 1 or n % 2 == 0)return 0;
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("input.txt", "r", stdin);
    int n;
    while(cin >> n){
        if(n < 0)break;
        int b = read();
        if(prime(n) and prime(getReverse(n, b))){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}