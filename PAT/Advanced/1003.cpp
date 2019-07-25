#include <bits/stdc++.h>
using namespace std;
template <typename T = int>
T read(){
    T x;
    cin >> x;
    return x;
}
int N, M, S, T;
struct Edge{
    int u,v,w;
};
typedef pair<int,int> pr;
vector<int>v, dis, vis, sum, num;
vector<Edge>edges;
vector<vector<int>>mp;
void addEdge(int x, int y, int z){ // 加边
    edges.push_back({x, y, z});
    mp[x].push_back(edges.size()-1);
}
void Dijkstra(int S){// 最小生成树算法
    for(auto &i: dis) i = -1;
    for(auto &i: mp[S]){
        Edge &e = edges[i];
        dis[e.v] = e.w;
    }
    dis[S] = 0;
    priority_queue<pr, vector<pr >, greater<pr>>Q;// 使用优先级队列找出最小的dis,优先弹出最小距离
    Q.push({dis[S], S});
    while(Q.size()){
        pr h = Q.top();
        Q.pop();
        if(vis[h.second])continue;// 保证每个点只出队一次
        vis[h.second] = 1;
        for(auto i: mp[h.second]){
            Edge &e = edges[i];
            if(dis[e.v] == -1 || dis[e.v] > dis[h.second] + e.w){// 优先根据距离最小的
                dis[e.v] = dis[h.second] + e.w;
                sum[e.v] += sum[h.second] + v[e.v];
                Q.push({dis[e.v], e.v});
            }else if(dis[e.v] == dis[h.second] + e.w and sum[e.v] < sum[h.second] + v[e.v] ){// 距离相同找点和最大的。
                sum[e.v] = sum[h.second] + v[e.v];
                Q.push({dis[e.v], e.v});
            }
        }
    }
}
int dfs(int S){// 递归过程打表记录每个点到终点T的最短路径数量
    if(S == T){
        return num[S] = 1;
    }
    int ans = 0;
    for(auto i: mp[S]){
        Edge& e = edges[i];
        if(dis[S] == dis[e.v] + e.w){// 递归动态规划打表存储
            if(num[e.v]){// 如果表中有记录，则读表中结果
                ans += num[e.v];
            }else{ // 如果表中暂无记录，则递归搜索
                ans += dfs(e.v);
            }
        }
    }
    return num[S] = ans;// 存表返回
}
int main(){
    freopen("input.txt", "r", stdin);
    N = read(), M = read(), S = read(), T = read();
    v.resize(N); // 每个点权值
    mp.resize(N); // 每个点邻边的下标集合
    dis.resize(N); // 每个点到源点的最短路径,本题是从终点开始进行Dijkstra算法，所以dis就是每个点到终点的最短路径
    sum.resize(N); // 每个点到终点的最短路径上的点权和
    vis.resize(N); // 每个点的是否进过队列被访问过的状态标记
    num.resize(N); // 每个点到终点的最短路径数量
    for(int i = 0; i < N; i++){
        v[i] = read();
    }
    for(int i = 0; i < M; i++){
        int x = read(), y = read(), z = read();
        addEdge(x, y, z);
        addEdge(y, x, z);
    }
    Dijkstra(T);// 从终点开始生成最小生成树
    dfs(S);
    // 输出入S点到T点的最短路径的数量，最短路径中最大点权和
    cout << num[S] << ' ' << sum[S] + v[T] << endl;
    return 0;
}