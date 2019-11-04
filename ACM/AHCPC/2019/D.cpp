//
// Created by zj on 19-5-31.
//

#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long LL;

template<typename T>
void OOM(T a, string s = "") {
    cerr << s << ":\t";
    for (auto e:a) {
        cerr << e.first << "," << e.second << " ";
    }
    cerr << endl;
}

template<typename T>
void OO(T a, string s = "") {
    cerr << s << ":\t";
    for (auto e:a) {
        cerr << e << " ";
    }
    cerr << endl;
}

template<typename T>
inline void oo(string str, T val) { cerr << str << val << endl; }

template<typename T>
inline T read() {
    T x;
    cin >> x;
    return x;
}


#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
struct ZJ{
    int v, p, q;
    ZJ(int v, int p, int q):v(v), p(p), q(q){}
};
void DIJ(int len, int source, int y, vector<vector<ZJ> >&V, vector<int>&dis, int type){
    vector<bool>book(len+1,false);
    dis[source] = 0;
    for(auto i: V[source]){
        if(type == 0){
            dis[i.v] = i.p;
        }else{
            dis[i.v] = i.q;
        }
    }
    OO(dis, "start print dis = ");
    book[source] = true;
    for(int i = 1; i < len; i++){
        cerr << "i = " << i << endl;
        int w = -1;
        int minDis = INT_MAX;
        for(int j = 1; j <= len; j++){
            if(book[j] || dis[j] >= minDis)continue;
            w = j;
            minDis = dis[j];
        }
        cerr << "w = " << w << "minDis = " << minDis << endl;
        book[w] = true;
        dis[w] = minDis;
        for(auto j: V[w]){
            if(book[j.v])continue;
            if(type == 0){
                cerr << "change dis = " << dis[w]+j.p<<endl;
                if(dis[j.v] > dis[w] + j.p){
                    dis[j.v] = dis[w] + j.p;
                }
            }else{
                if(dis[j.v] > dis[w] + j.q){
                    dis[j.v] = dis[w] + j.q;
                }
            }
        }
        OO(dis, "dis= ");
        OO(book, "book= ");
    }
}
int main(){
    ifstream cin("input.txt");
    int n, m;
    cin >> n >> m;
    vector< vector<ZJ> > V1(n+1), V2(n+1);//V1是反向图，V2是原图
    for(int i = 0; i < m; i++){
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        V1[v].emplace_back(ZJ(u, p, q));
        V2[u].emplace_back(ZJ(v, p, q));
    }
    for(int i = 1; i <= n; i++){
        cerr << i <<": ";
        for(auto j : V1[i]){
            cerr << j.v << " " << j.p << " " << j.q << endl;
        }
    }
    vector<int>dis_a(n+1, INT_MAX / 2), dis_hero(n+1, INT_MAX / 2);
    OO(dis_hero);
    OO(dis_a);
    DIJ(n, n, 1, V1, dis_hero, 0);
    OO(dis_hero, "final dis_hero = ");
    DIJ(n, n, 1, V1, dis_a, 1);
    OO(dis_a, "final dis_a = ");
    vector<int>dis(n+1, INT_MAX/2);
    for(auto i:V2[1]){
        dis[i.v] = (dis_hero[i.v] + i.p > dis_hero[1]) + (dis_a[i.v] + i.q > dis_a[1]);
    }
    dis[1] = 0;
    vector<bool>book(n+1, false);
    book[1] = true;
    for(int i = 1; i < n; i++){
        int w = -1, minDis = INT_MAX/2;
        for(int j = 1; j <= n; j++){
            if(book[j] == 0 and dis[j] < minDis){
                w = j;
                minDis = dis[j];
            }
        }
        cerr << "w = " << w << endl;
        book[w] = true;
        for(auto j : V2[w]){
            if(book[j.v])continue;
            int t = (dis_hero[j.v] + j.p > dis_hero[w]) + (dis_a[j.v] + j.q > dis_a[w]);
            if(dis[j.v] > dis[w] + t){
                dis[j.v] = dis[w] + t;
            }
        }
        OO(dis, "dis = ");
    }
    cout << dis[n] << endl;
    return 0;
}
/*
5 7
3 4 7 1
1 3 2 20
1 4 17 18
4 5 25 3
1 2 10 1
3 5 4 14
2 4 6 5
1
5 7
3 4 7 11
1 3 2 20
1 4 7 18
4 5 2 3
1 2 1 10
3 5 14 4
2 4 6 5
0
4 6
1 2 13 40
2 3 7 12
1 3 15 6
1 4 11 2
2 4 14 1
3 4 29 14
0
 */