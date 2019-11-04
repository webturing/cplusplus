#include<bits/stdc++.h>

using namespace std;
int n = 4;
vector<bool> vis(n, 0);//STL Array
vector<int> a(n, 0);

void dfs(int k) {//k搜索的深度
    if (k >= 4) {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (vis[i])continue;// 剪枝
        vis[i] = true;
        a[k] = i;
        dfs(k + 1);//深度优先搜索
        vis[i] = false;
    }
}


int main() {
    dfs(0);
    return 0;
}