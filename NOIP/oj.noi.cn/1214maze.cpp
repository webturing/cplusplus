//
// Created by jal on 2018/6/25 0025.
//
#include <bits/stdc++.h>
using  namespace std;
set<pair<int,int>>G, barriers;
int sum = 0;
void dfs(pair<int, int> start, pair<int , int > end){
    if(start.first == end.first && start.second == end.second){
        sum++;
        return;
    }
    int x = start.first, y = start.second;
    vector<pair<int, int>>next{make_pair(x, y+1), make_pair(x, y-1), make_pair(x-1, y), make_pair(x+1, y)};
    for(pair<int, int> k  : next){
        auto temp = find(G.begin(), G.end(), k);
        if (temp != G.end()){
            G.erase(temp);
            dfs(k, end);
            G.insert(k);
        }
    }
    return ;
}
int main(){
    ifstream cin("input.txt");
    int n,m,t;
    cin >> n >> m >> t;
    pair<int, int > start;
    cin >> start.first >> start.second;
    pair<int, int > end;
    cin >> end.first >> end.second;
    for(int i = 1; i <= t; i++){
        pair<int , int > barrier;
        cin >> barrier.first >> barrier.second;
        barriers.insert(barrier);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pair <int , int > point = make_pair(i,j);
            if(barriers.empty() || barriers.find(point) == barriers.end()){
                G.insert(point);
            }
        }
    }
    G.erase(G.find(start));
    dfs(start, end);
    cout << sum << endl;
}
