#include<bits/stdc++.h>

using namespace std;

bool prime(int n) {//O(sqrt(n)/2)
    if (n == 2)return true;
    if (n < 2 || n % 2 == 0)return false;
    for (int c = 3; c * c <= n; c += 2)if (n % c == 0)return false;
    return true;
}

int n = 4;
vector<bool> vis(n, 0);//STL Array
vector<int> a(n, 0);

bool ok() {//for i from [0,n-1) check (a[i]+a[(i+1）%n]) is prime or not

}

void dfs(int k) {//k搜索的深度
    if (k >= n) {
        if (ok()) {
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i])continue;// 剪枝
        vis[i] = true;
        a[k] = i + 1;
        dfs(k + 1);//深度优先搜索
        vis[i] = false;
    }
}


int main() {
    int n;
    if (n % 2 == 1) {
        cout << "no solution" << endl;
    }
    a[0] = 1;
    vis[0] = true;
    dfs(1);
    return 0;
}