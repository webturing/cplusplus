#include <bits/stdc++.h>
// n的全排列
using namespace std;
int n;
const int MAXN = 10;
int out[MAXN], book[MAXN];
bool isPrime(int n){
    if(n <= 1 )return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;
    for(int i = 3; i * i <= n; i+=2){
        if( n % i == 0)return false;
    }
    return true;
}
int flag = 0;
void dfs(int step){
    if(step >= n){
        if(isPrime(out[0]+out[n-1])){
            flag  = 1;
            for(int i = 0; i < n; i++){
                cout <<out[i] << " ";
            }
            cout <<endl;
        }
        return;
    }
    for(int i = 2; i <= n; i++){
        if( book[i] == 0){
            if(isPrime(out[step-1] + i)){
                out[step] = i;
                book[i] = 1;
                dfs(step+1);
                book[i] = 0;
            }
        }
    }
}
int main(){
    n = 4;
    book[1] = 1;
    out[0] = 1;
    dfs(1);
    if(flag == 0){
        cout << "No way!" << endl;
    }
}
