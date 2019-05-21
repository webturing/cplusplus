#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<LL> a(n, 0);

    for (auto &e:a)cin >> e;
    vector<LL> b(n + 1, 0);
    partial_sum(a.begin(), a.end(), b.begin() + 1);

    map<int, vector<pair<int, int> >> M;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            M[b[j] - b[i + 1]].push_back(make_pair(i + 1, j));
    int gmax=0,sum=0;
    for(auto p:M)if(p.second.size()>gmax){
            gmax=p.first;

        }
    cout<<M[gmax].size()<<endl;
    for(auto p:M[gmax])
        cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
