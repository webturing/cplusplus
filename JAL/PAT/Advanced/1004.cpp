//
// Created by jal on 2019-07-25.
//

#include <bits/stdc++.h>
using namespace std;
template <typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
typedef pair<int, int> pr;
int main(){
//    freopen("input.txt", "r", stdin);
    int n = read(), m = read();
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>>v(n+1);
    vector<int>vis(n+1);
    for(int i = 0; i < m; i++){
        int id = read(), k = read();
        for(int j = 0; j < k; j++){
            v[id].push_back(read());
        }
    }
    priority_queue<pr, vector<pr>, greater<pr>>Q;
    Q.push({0, 1});
    vector<int>result;
    int cnt = 0; // 当前行叶节点的数目
    int lastV = -1, curV = 0; // 上一个点的层级，当前点的层级
    while(Q.size()){
        pr h = Q.top();
        Q.pop();
        curV = h.first;
        if(lastV != curV){
            result.push_back(cnt);
//            cerr << h.first << ' ' << h.second << endl;
            cnt = 0;
        }
        if(v[h.second].size() == 0){
            cnt++;
        }
        lastV = curV;
        for(auto i: v[h.second]){
            if(vis[i] == 0){
                vis[i] = 1;
                Q.push({h.first+1, i});
            }
        }
    }
    result.push_back(cnt);
    for(int i = 1; i < result.size(); i++){
        if(i!=1){
            cout << ' ' << result[i];
        }else{
            cout << result[i];
        }
    }
    cout << endl;
    return 0;
}