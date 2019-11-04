#include<bits/stdc++.h>
using namespace std;
int k, m, n, len, sum, f = 0;
vector<int>out;
void dfs(int step){
    if(step >= len){
        if(sum == n){
            f = 1;
            cout << n << " ";
            for(auto i: out){
                cout << i;
            }
            for(int i = 1; i <= k-len; i++){
                cout << 9;
            }
            cout << endl;
        }
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(step == 0 and i == 0)continue;// 最高位不能为0
        if(step == len-1 and i == 9)continue;// 关键。第len-1位不能为9，否则A末尾则超过了k-len个9
        out[step] = i;
        sum += i;
        dfs(step+1);
        sum -= i;
    }
}
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
bool prime(int n){
    if(n <= 2)return false;// 此处把2也直接返回false。
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> k >> m;
        f = 0;
        cout << "Case " << t << endl;
        for(int i = k; i >= 2; i--){
            n = m - 9 * i + 1;
            if(prime(gcd(m, n))){// m,n的最大公约数为超过2的素数
                len = k - i;
                out.clear();
                out.resize(len);
                sum = 0;
                dfs(0);
            }
        }
        if(f == 0){
            cout << "No solution" << endl;
        }
    }
}
