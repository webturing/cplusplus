#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>G(n+1);
    for(int i = 1; i <= n; i++){
        G[i].resize(n+1);
        for(int j = 1; j <= n; j++){
            if(i==j){
                G[i][j] = 0;
            }else{
                G[i][j] = INT_MAX/2;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = min(G[x][y], z);
    }
    int q;
    cin >> q;
    while(q--){
        bool f = true;
        vector<int>v(n+1);
        for(int i = 1; i<= n; i++){
            cin >> v[i];
        }
        int source = v[1];
        vector<int>dis(n+1), book(n+1);
        for(int i = 1; i <= n; i++){
            dis[i] = G[source][i];
        }
        book[source] = 1;
        for(int i = 2; i < v.size(); i++){
            int p = -1, MIN = INT_MAX;
            for(int j = 1; j <= n; j++){
                if(book[j]==0 and dis[j] < MIN){
                    MIN = dis[j];
                    p = j;
                }
            }
            if(dis[v[i]] != MIN){// 核心部分
                f = false;
                cout << "No" << endl;
                break;
            }
            p = v[i];
            book[p] = 1;
            for(int j = 1; j <= n; j++){
                if(book[j] == 0 and dis[j] > dis[p] + G[p][j] ){
                    dis[j] = dis[p] + G[p][j];
                }
            }
        }
        if(f){
            cout << "Yes" << endl;
        }
    }
}
